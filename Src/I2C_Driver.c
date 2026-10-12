#include "I2C_Driver.h"
#include "GPIO_Driver.h"
#include "RCC_Driver.h"
#include "stdint.h"


void I2C_Init(I2C_Struct_T *i2cConfig){
	uint32_t I2C_PeripheralClockFreq;
	uint32_t ReqMhz;
	I2C_RegDef_T *pI2c;

    if(!i2cConfig)
        return;

    pI2c = i2cConfig->I2C_Instance;

    /* Configure the GPIO Peripheral for the given USART peripheral */
    if(!pI2c)
        return;

    RCC_Enable_I2C(pI2c);
    I2C_ConfigureGPIO(i2cConfig->I2C_ID);

    pI2c->I2C_CR1 &= ~ I2C_CR1_PE; // Disable I²C

    I2C_PeripheralClockFreq = RCC_Get_PCLK1();

    pI2c->I2C_CR2 &= ~I2C_CR2_FREQ_MASK;

    pI2c->I2C_CR2 |= (I2C_PeripheralClockFreq / 1000000U);

    /*CCR macros related macros for the I2C Peripheral*/
    pI2c->I2C_CCR &= ~I2C_CCR_CCR_MASK;

    /*CCR = PCLK1 / (2 × I2C_BusSpeed)*/
    pI2c->I2C_CCR |= I2C_PeripheralClockFreq / (2 * i2cConfig->I2C_BusSpeed);

    pI2c->I2C_TRISE &= ~I2C_TRISE_MASK;

    ReqMhz = I2C_PeripheralClockFreq / 1000000U;

    pI2c->I2C_TRISE |= ReqMhz + 1U;


    pI2c->I2C_CR1 &= ~I2C_CR1_ACK;

    if (i2cConfig->ACKs_bit == ACK_EN){
        pI2c->I2C_CR1 |= I2C_CR1_ACK;
    }

    pI2c->I2C_CR1 |= I2C_CR1_PE;

}
void I2C_DeInit(I2C_Struct_T *i2cConfig){
    if(!i2cConfig)
        return;

    /* Disable I2C through CR1 Register */
    i2cConfig->I2C_Instance->I2C_CR1 &= ~(I2C_CR1_PE);

    /* Disable I2C Peripheral Clock */
    RCC_Disable_I2C(i2cConfig->I2C_Instance);
}

void I2C_Enable(I2C_Struct_T *i2cConfig){
	I2C_RegDef_T *pI2c;

    if(!i2cConfig)
        return;

    pI2c = i2cConfig->I2C_Instance;

    if(!pI2c)
        return;

    pI2c->I2C_CR1 |= I2C_CR1_PE;
}
void I2C_Disable(I2C_Struct_T *i2cConfig){
	I2C_RegDef_T *pI2c;

    if(!i2cConfig)
        return;

    pI2c = i2cConfig->I2C_Instance;

    if(!pI2c)
        return;

    pI2c->I2C_CR1 &= ~I2C_CR1_PE;
}

void I2C_MasterTransmit(I2C_Struct_T *i2cConfig, uint8_t slaveAddress, uint8_t *data, uint8_t length){
    I2C_RegDef_T *pI2C;
    uint32_t timeout;

    if(!i2cConfig || !data || !length || !slaveAddress)
        return;

    pI2C = i2cConfig->I2C_Instance;

    if(!pI2C)
        return;
    /* Generate START condition */
    pI2C->I2C_CR1 |= I2C_CR1_START;

	/* Wait until START condition is generated */
    /* Wait for START condition */
    timeout = 0;

    while (1)
    {
        if (pI2C->I2C_SR1 & I2C_SR1_SB)
        {
            break;
        }

        if (++timeout >= 100000U)
        {
            pI2C->I2C_CR1 |= I2C_CR1_STOP;
            return;
        }
    }

	/* Send slave address + WRITE bit */
	pI2C->I2C_DR = (slaveAddress << 1);

	/* Wait for address acknowledge */
	timeout = 0;
	while(!(pI2C->I2C_SR1 & I2C_SR1_ADDR)){
        /* Slave did not acknowledge */
        if(pI2C->I2C_SR1 & I2C_SR1_AF){
            pI2C->I2C_SR1 &= ~I2C_SR1_AF;
            pI2C->I2C_CR1 |= I2C_CR1_STOP;
            return;
        }

        if(++timeout > 100000U){
            pI2C->I2C_CR1 |= I2C_CR1_STOP;
            return;
        }
    }

	/* Clear ADDR flag: read SR1 followed by SR2 */
	pI2C->I2C_SR1;
	pI2C->I2C_SR2;

	 /* Transmit data */
	    for(uint32_t i = 0; i < length; i++){
	        timeout = 0;

	        /* Wait until data register is empty */
	        while(!(pI2C->I2C_SR1 & I2C_SR1_TXE)){
	            if(pI2C->I2C_SR1 & I2C_SR1_AF){
	                pI2C->I2C_SR1 &= ~I2C_SR1_AF;
	                pI2C->I2C_CR1 |= I2C_CR1_STOP;
	                return;
	            }

	            if(++timeout > 100000U){
	                pI2C->I2C_CR1 |= I2C_CR1_STOP;
	                return;
	            }
	        }
	        /* Transmit current data byte */
	        pI2C->I2C_DR = data[i];
	    }

	    /* Wait until final byte transfer is complete */
	    timeout = 0;

	    while(!(pI2C->I2C_SR1 & I2C_SR1_BTF)){
	        if(++timeout > 100000U){
	            pI2C->I2C_CR1 |= I2C_CR1_STOP;
	            return;
	        }
	    }

	    /* Generate STOP condition */

    pI2C->I2C_CR1 |= I2C_CR1_STOP;

}
void I2C_MasterReceive(I2C_Struct_T *i2cConfig,uint8_t slaveAddress, uint8_t *data, uint8_t length){
    I2C_RegDef_T *pI2C;
    uint32_t timeout;

    if(!i2cConfig || !data || !length || !slaveAddress)
        return;

    pI2C = i2cConfig->I2C_Instance;

    if(!pI2C)
        return;

    /* Generate START condition */
    pI2C->I2C_CR1 |= I2C_CR1_START;

    /* Wait until START condition is generated */
    timeout = 0;
    while(!(pI2C->I2C_SR1 & I2C_SR1_SB))
    {
        if(++timeout > 100000U)
            return;
    }

    /* Send slave address + READ bit */
    pI2C->I2C_DR = (slaveAddress << 1) | 1U;

    /* Wait for address acknowledgement */
    timeout = 0;
    while(!(pI2C->I2C_SR1 & I2C_SR1_ADDR))
    {
        if(pI2C->I2C_SR1 & I2C_SR1_AF)
        {
            pI2C->I2C_SR1 &= ~I2C_SR1_AF;
            pI2C->I2C_CR1 |= I2C_CR1_STOP;
            return;
        }

        if(++timeout > 100000U)
        {
            pI2C->I2C_CR1 |= I2C_CR1_STOP;
            return;
        }
    }

    /*
     * Receive data
     *
     * ACK is kept enabled while receiving bytes.
     */
    for(uint32_t i = 0; i < length; i++)
    {
        if(i == (length - 1U))
        {
            /*
             * Last byte:
             * Disable ACK so the slave receives NACK.
             */
            pI2C->I2C_CR1 &= ~I2C_CR1_ACK;

            /* Clear ADDR: read SR1 followed by SR2 */
            pI2C->I2C_SR1;
            pI2C->I2C_SR2;

            /* Generate STOP before reading final byte */
            pI2C->I2C_CR1 |= I2C_CR1_STOP;
        }
        else
        {
            /*
             * Clear ADDR for normal reception.
             */
            pI2C->I2C_SR1;
            pI2C->I2C_SR2;
        }

        /* Wait until received byte is available */
        timeout = 0;

        while(!(pI2C->I2C_SR1 & I2C_SR1_RXNE))
        {
            if(++timeout > 100000U)
            {
                pI2C->I2C_CR1 |= I2C_CR1_STOP;
                return;
            }
        }

        /* Read received byte */
        data[i] = (uint8_t)pI2C->I2C_DR;
    }

    /*
     * Re-enable ACK for the next reception.
     */
    pI2C->I2C_CR1 |= I2C_CR1_ACK;
}


void I2C_ConfigureGPIO(I2C_EN_ID_T i2cId){

    GPIO_PINCONFIG_T Gpioi2cPinConfig = {
        .pin = 0,
        .mode = GPIO_MODE_ALT,
        .otype = GPIO_OTYPE_OD,
        .speed = GPIO_SPEED_HIGH,
        .pupdr = GPIO_NO_PULL,
        .alternatefunc = 0
    };


    /* Configure the GPIO for I2C_1_ID */
    if(i2cId == I2C_1_ID) {
    	/*SCL = PB8
    	 *SDA = PB9
    	 *AF = AF4
    	 * */
        RCC_Enable_GPIO(GPIOB);

        Gpioi2cPinConfig.pin = 8;
        Gpioi2cPinConfig.alternatefunc = 4;
        GPIO_Init(GPIOB, &Gpioi2cPinConfig);

        Gpioi2cPinConfig.pin = 9;
        GPIO_Init(GPIOB, &Gpioi2cPinConfig);
    }


    /* Configure the GPIO for I2C_2_ID */
    else if(i2cId == I2C_2_ID) {
    	/*SCL = PB10
    	 *SDA = PB11
    	 *AF = AF4
    	 * */
        RCC_Enable_GPIO(GPIOB);

        Gpioi2cPinConfig.pin = 10;
        Gpioi2cPinConfig.alternatefunc = 4;
        GPIO_Init(GPIOB, &Gpioi2cPinConfig);

        Gpioi2cPinConfig.pin = 11;
        GPIO_Init(GPIOB, &Gpioi2cPinConfig);
    }


    /* Configure the GPIO for I2C_3_ID */
    else if(i2cId == I2C_3_ID) {
    	/*SCL = PA8
    	 *SDA = PC9
    	 *AF = AF4
    	 * */

        RCC_Enable_GPIO(GPIOA);

        Gpioi2cPinConfig.pin = 8;
        Gpioi2cPinConfig.alternatefunc = 4;
        GPIO_Init(GPIOA, &Gpioi2cPinConfig);

        RCC_Enable_GPIO(GPIOC);
        Gpioi2cPinConfig.pin = 9;
        Gpioi2cPinConfig.alternatefunc = 4;
        GPIO_Init(GPIOC, &Gpioi2cPinConfig);
    }


    /* Configure the GPIO for I2CFMP1_ID */
    else if(i2cId == I2CFMP1_ID) {
    	/*SCL = PB15
    	 *SDA = PB14
    	 *AF = AF4
    	 * */

        RCC_Enable_GPIO(GPIOB);

        Gpioi2cPinConfig.pin = 15;
        Gpioi2cPinConfig.alternatefunc = 4;
        GPIO_Init(GPIOB, &Gpioi2cPinConfig);

        Gpioi2cPinConfig.pin = 14;
        GPIO_Init(GPIOB, &Gpioi2cPinConfig);
    }
}
