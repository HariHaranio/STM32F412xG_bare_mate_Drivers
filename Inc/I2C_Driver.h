#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_

#include "stm32f412xG.h"

typedef enum {
	I2C_1_ID,
	I2C_2_ID,
	I2C_3_ID,
	I2CFMP1_ID
}I2C_EN_ID_T;


typedef enum{
	ACK_DEN,
	ACK_EN
}ACKs_BITS_T;


typedef struct {

	I2C_EN_ID_T I2C_ID;
	I2C_RegDef_T *I2C_Instance;
	uint32_t I2C_BusSpeed;
	ACKs_BITS_T ACKs_bit;

}I2C_Struct_T;


void I2C_Init(I2C_Struct_T *i2cConfig);     															//| Configure the selected I²C peripheral            |
void I2C_DeInit(I2C_Struct_T *i2cConfig);         														//| Disable/De-nitialize the selected I²C peripheral |
void I2C_Enable(I2C_Struct_T *i2cConfig);         														//| Set I²C peripheral enable                        |
void I2C_Disable(I2C_Struct_T *i2cConfig);        														//| Disable I²C peripheral                           |
void I2C_MasterTransmit(I2C_Struct_T *i2cConfig, uint8_t slaveAddress, uint8_t *data, uint8_t length); 	//| Master → Slave data                              |
void I2C_MasterReceive(I2C_Struct_T *i2cConfig,uint8_t slaveAddress, uint8_t *data, uint8_t length);	//| Slave → Master data                              |
void I2C_ConfigureGPIO(I2C_EN_ID_T i2cId);	 															//| Configure SDA/SCL pins for the selected I²C      |

 #endif /* I2C_DRIVER_H_ */
