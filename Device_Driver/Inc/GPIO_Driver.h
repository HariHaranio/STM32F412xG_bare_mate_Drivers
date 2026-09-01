#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include "stm32f412xG.h"

typedef enum
{
	GPIO_MODE_INPUT = 0x00,
	GPIO_MODE_OUTPUT= 0x01,
	GPIO_MODE_ALT	= 0x02,
	GPIO_MODE_ANALOG= 0x03
}GPIO_MODE_T;

typedef enum
{
	GPIO_OTYPE_PP = 0,
	GPIO_OTYPE_OD = 1
}GPIO_OTYPER_T;


typedef enum
{
	GPIO_SPEED_LOW = 0x00,
	GPIO_SPEED_MED = 0x01,
	GPIO_SPEED_FAST= 0x02,
	GPIO_SPEED_HIGH= 0x03
}GPIO_SPEED_T;

typedef enum
{
	GPIO_NO_PULL  = 0x00,
	GPIO_PULL_UP  = 0x01,
	GPIO_PULL_DOWN= 0x02,
	GPIO_PULL_RSVD= 0x03
}GPIO_PUPDR_T;

typedef struct
{
	uint8_t pin;
	GPIO_MODE_T mode;
	GPIO_OTYPER_T otype;
	GPIO_SPEED_T speed;
	GPIO_PUPDR_T pupdr;
	uint8_t alternatefunc;

}GPIO_PINCONFIG_T;


/*GPIO function declarations*/
void GPIO_Init(GPIO_RegDef *port, GPIO_PINCONFIG_T *pinConfig);
void GPIO_DeInit_Pin(GPIO_RegDef *port,GPIO_PINCONFIG_T *pinConfig);
void GPIO_DeInit(GPIO_RegDef *port);

void GPIO_TogglePin(GPIO_RegDef *port, uint8_t pin);
void GPIO_SetPin(GPIO_RegDef *port, uint8_t pin);
void GPIO_ResetPin(GPIO_RegDef *port, uint8_t pin);
uint8_t GPIO_ReadPin(GPIO_RegDef *port, uint8_t pin);
void GPIO_WritePort(GPIO_RegDef *port, uint32_t portVal);
uint32_t GPIO_ReadPort(GPIO_RegDef *port);
void GPIO_Lock(GPIO_RegDef *port, uint8_t pin);




#endif
