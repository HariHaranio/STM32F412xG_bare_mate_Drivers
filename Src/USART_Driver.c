#include "USART_Driver.h"
#include "GPIO_Driver.h"
#include "RCC_Driver.h"
#include "stdint.h"

uint32_t USART_PeripheralClockFreq;

/* This function initializes the USART Peripheral based on the USARTID passed through the Config Struct */
void USART_Init(USART_Struct_T *usartConfig)
{
    uint8_t Over8Val;
    float UsartDiv, fraction;
    uint32_t Mantissa;
    uint32_t FractionValue;
    USART_RegDef_T *pUsart;

    if(!usartConfig)
        return;

    pUsart = usartConfig->USARTInstance;

    /* Configure the GPIO Peripheral for the given USART peripheral */
    if(!pUsart)
        return;

    RCC_EnableUSART(pUsart);
    USART_ConfigureGPIO(usartConfig->usartID);


    /* Set the Word Length */
    if(usartConfig->wordLength == USART_WORDLENGTH_8B){
        pUsart->CR1 &= ~(1 << 12);
    }

    else{
        pUsart->CR1 |= (1 << 12); // 9 bits word length
    }


    /* Set the Stop bits */
    pUsart->CR2 &= ~(0b11 << 12);

    if(usartConfig->stopBits == USART_STOPBITS_0_5){
        pUsart->CR2 |= USARTx_CR2_STOPBIT0_5;
    }

    else if(usartConfig->stopBits == USART_STOPBITS_1){
        pUsart->CR2 |= USARTx_CR2_STOPBIT1;
    }

    else if(usartConfig->stopBits == USART_STOPBITS_1_5){
        pUsart->CR2 |= USARTx_CR2_STOPBIT1_5;
    }

    else if(usartConfig->stopBits == USART_STOPBITS_2) {
        pUsart->CR2 |= USARTx_CR2_STOPBIT2;
    }else{
    	// ------*-------
    }


    /* Enable or Disable Parity */
    if(usartConfig->parity != USART_PARITY_NONE)
    {
        /* Enable Parity */
        pUsart->CR1 |= (1 << 10);

        /* Set the Parity */
        if(usartConfig->parity == USART_PARITY_EVEN){
            pUsart->CR1 &= ~(1 << 9);
        }

        else if(usartConfig->parity == USART_PARITY_ODD){
            pUsart->CR1 |= (1 << 9);
        }
    }


    /* Set Oversampling Flag OVER8 */
    if(usartConfig->oversampling == 8){
        pUsart->CR1 |= USARTx_CR1_OVER8;
        Over8Val = 1;
    }

    else if(usartConfig->oversampling == 16){
        pUsart->CR1 &= ~USARTx_CR1_OVER8;
        Over8Val = 0;
    }


    /* Get USART peripheral clock */
    if((pUsart == USART1) || (pUsart == USART6)) {
        USART_PeripheralClockFreq = RCC_GetPCLK2();
    }
    else{
        USART_PeripheralClockFreq = RCC_GetPCLK1();
    }


    /* Set the Baud rate */
    /*
     * USARTDIV = Fclk / (8 x (2 - OVER8) x BaudRate)
     */
    UsartDiv = (USART_PeripheralClockFreq /
                (8 * (2 - Over8Val) * usartConfig->baudrate));

    Mantissa = (uint32_t)UsartDiv;

    /* Calculate fractional part */
    fraction = UsartDiv - Mantissa;

    /*
     * Convert fractional part to BRR fraction.
     *
     * Oversampling by 8:
     *     Fraction = fraction * 8
     *
     * Oversampling by 16:
     *     Fraction = fraction * 16
     */
    if(Over8Val == 1){
        FractionValue = (uint32_t)(fraction * 8 + 0.5f);
    }else{
        FractionValue = (uint32_t)(fraction * 16 + 0.5f);
    }

    /* Configure Baud Rate Register */
    pUsart->BRR = (Mantissa << 4) | FractionValue;


    /* Enable Transmitter / Receiver */
    /* Enable USART */
    pUsart->CR1 |= (USARTx_CR1_TE) |
                   (USARTx_CR1_RE) |
                   (USARTx_CR1_UE);
}


/* This function DeInitializes the USART peripheral based on the USART ID passed as a param */
void USART_DeInit(USART_Struct_T *usartConfig){
    if(!usartConfig)
        return;

    /* Disable USART through CR1 Register */
    usartConfig->USARTInstance->CR1 &= ~(USARTx_CR1_UE);

    /* Disable USART Peripheral Clock */
    RCC_DisableUSART(usartConfig->USARTInstance);
}


/* This function transmits the data of length passed as param */
void USART_Transmit(USART_Struct_T *usartConfig, uint8_t *data, uint8_t length){
    USART_RegDef_T *pUsart;

    if(!usartConfig || !data || !length)
        return;

    pUsart = usartConfig->USARTInstance;

    if(!pUsart)
        return;

    for(uint32_t i = 0; i < length; i++){

        while(!(pUsart->SR & USARTx_SR_TXE));

        /* Transmit the data */
        pUsart->DR = data[i] & 0xff;
    }

    /* Check the TC Flag */
    while(!(pUsart->SR & USARTx_SR_TC));
}


/* This function prepares the global buffers to transmit data in Interrupt mode */
void USART_Transmit_IT(USART_Struct_T *usartConfig, uint8_t *data, uint8_t length){
    if(!usartConfig || !data || length == 0)
        return;

    if(usartConfig->TxBusy == 1)
        return;

    usartConfig->pTxBuffer = data;
    usartConfig->TxLength = length;
    usartConfig->TxIndex = 0;
    usartConfig->TxBusy = 1;

    usartConfig->USARTInstance->CR1 |= USARTx_CR1_TXEIE;
}


/* This function receives the data through the data buffer of length passed as param */
void USART_Receive(USART_Struct_T *usartConfig, uint8_t *data, uint8_t length){
    USART_RegDef_T *pUsart;

    if(!usartConfig || !data || !length)
        return;

    pUsart = usartConfig->USARTInstance;

    if(!pUsart)
        return;

    for(uint32_t i = 0; i < length; i++){
        /* Check the RXNE Flag in SR */
        while(!(pUsart->SR & USARTx_SR_RXNE));

        /* Read the DR */
        data[i] = pUsart->DR & 0xFF;
    }
}


/* Support functions */

/* Setup the buffers to receive data in Interrupt mode */
void USART_Receive_IT(USART_Struct_T *usartConfig, uint8_t *data, uint8_t length) {
    if(!usartConfig || !data || length == 0)
        return;

    if(!usartConfig->USARTInstance)
        return;

    if(usartConfig->RxBusy == 1)
        return;

    usartConfig->pRxBuffer = data;
    usartConfig->RxLength = length;
    usartConfig->RxIndex = 0;
    usartConfig->RxBusy = 1;

    usartConfig->USARTInstance->CR1 |= USARTx_CR1RXNEIE;
}


/* This function enables the USART for given USART Peripheral ID */
void USART_Enable(USART_Struct_T *usartConfig){
    USART_RegDef_T *pUsart;

    if(!usartConfig)
        return;

    pUsart = usartConfig->USARTInstance;

    if(!pUsart)
        return;

    pUsart->CR1 |= USARTx_CR1_UE;
}


/* This function disables the USART for given USART Peripheral ID */
void USART_Disable(USART_Struct_T *usartConfig){
    USART_RegDef_T *pUsart;

    if(!usartConfig)
        return;

    pUsart = usartConfig->USARTInstance;

    if(!pUsart)
        return;

    pUsart->CR1 &= ~USARTx_CR1_UE;
}


void USART_ConfigureGPIO(USART_EN_ID_T usartId){
    GPIO_PINCONFIG_T GpioUsartPinConfig = {
        .pin = 0,
        .mode = GPIO_MODE_ALT,
        .otype = GPIO_OTYPE_PP,
        .speed = GPIO_SPEED_HIGH,
        .pupdr = GPIO_NO_PULL,
        .alternatefunc = 0
    };


    /* Configure the GPIO for USART1 */
    if(usartId == USART1_ID) {
        /*
         * PA9  - USART1_TX
         * PA10 - USART1_RX
         * Alternate Function - 7
         */

        RCC_EnableGPIO(GPIOA);

        GpioUsartPinConfig.pin = 9;
        GpioUsartPinConfig.alternatefunc = 7;
        GPIO_Init(GPIOA, &GpioUsartPinConfig);

        GpioUsartPinConfig.pin = 10;
        GPIO_Init(GPIOA, &GpioUsartPinConfig);
    }


    /* Configure the GPIO for USART2 */
    else if(usartId == USART2_ID) {
        /*
         * PA2 - USART2_TX
         * PA3 - USART2_RX
         * Alternate Function - 7
         */

        RCC_EnableGPIO(GPIOA);

        GpioUsartPinConfig.pin = 2;
        GpioUsartPinConfig.alternatefunc = 7;
        GPIO_Init(GPIOA, &GpioUsartPinConfig);

        GpioUsartPinConfig.pin = 3;
        GPIO_Init(GPIOA, &GpioUsartPinConfig);
    }


    /* Configure the GPIO for USART3 */
    else if(usartId == USART3_ID) {
        /*
         * PD8 - USART3_TX
         * PD9 - USART3_RX
         * Alternate Function - 7
         */

        RCC_EnableGPIO(GPIOD);

        GpioUsartPinConfig.pin = 8;
        GpioUsartPinConfig.alternatefunc = 7;
        GPIO_Init(GPIOD, &GpioUsartPinConfig);

        GpioUsartPinConfig.pin = 9;
        GPIO_Init(GPIOD, &GpioUsartPinConfig);
    }


    /* Configure the GPIO for USART6 */
    else if(usartId == USART6_ID) {
        /*
         * PC6 - USART6_TX
         * PC7 - USART6_RX
         * Alternate Function - 8
         */

        RCC_EnableGPIO(GPIOC);

        GpioUsartPinConfig.pin = 6;
        GpioUsartPinConfig.alternatefunc = 8;
        GPIO_Init(GPIOC, &GpioUsartPinConfig);

        GpioUsartPinConfig.pin = 7;
        GPIO_Init(GPIOC, &GpioUsartPinConfig);
    }
}
