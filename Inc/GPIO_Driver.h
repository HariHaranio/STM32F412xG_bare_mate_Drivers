#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include "stm32f412xG.h"

#define GPIO_PIN_0                  ((uint8_t)0U)    /* Pin 0 selected    */
#define GPIO_PIN_1                  ((uint8_t)1U)    /* Pin 1 selected    */
#define GPIO_PIN_2                  ((uint8_t)2U)    /* Pin 2 selected    */
#define GPIO_PIN_3                  ((uint8_t)3U)    /* Pin 3 selected    */
#define GPIO_PIN_4                  ((uint8_t)4U)    /* Pin 4 selected    */
#define GPIO_PIN_5                  ((uint8_t)5U)    /* Pin 5 selected    */
#define GPIO_PIN_6                  ((uint8_t)6U)    /* Pin 6 selected    */
#define GPIO_PIN_7                  ((uint8_t)7U)    /* Pin 7 selected    */
#define GPIO_PIN_8                  ((uint8_t)8U)    /* Pin 8 selected    */
#define GPIO_PIN_9                  ((uint8_t)9U)    /* Pin 9 selected    */
#define GPIO_PIN_10                 ((uint8_t)10U)   /* Pin 10 selected   */
#define GPIO_PIN_11                 ((uint8_t)11U)   /* Pin 11 selected   */
#define GPIO_PIN_12                 ((uint8_t)12U)   /* Pin 12 selected   */
#define GPIO_PIN_13                 ((uint8_t)13U)   /* Pin 13 selected   */
#define GPIO_PIN_14                 ((uint8_t)14U)   /* Pin 14 selected   */
#define GPIO_PIN_15                 ((uint8_t)15U)   /* Pin 15 selected   */

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
	GPIO_OTYPE_OD = 1		// open drain
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
void GPIO_Init(GPIO_RegDef_T *port, GPIO_PINCONFIG_T *pinConfig);
void GPIO_DeInit_Pin(GPIO_RegDef_T *port,GPIO_PINCONFIG_T *pinConfig);
void GPIO_DeInit(GPIO_RegDef_T *port);

void GPIO_TogglePin(GPIO_RegDef_T *port, uint8_t pin);
void GPIO_SetPin(GPIO_RegDef_T *port, uint8_t pin);
void GPIO_ResetPin(GPIO_RegDef_T *port, uint8_t pin);
uint8_t GPIO_ReadPin(GPIO_RegDef_T *port, uint8_t pin);
void GPIO_WritePort(GPIO_RegDef_T *port, uint32_t portVal);
uint32_t GPIO_ReadPort(GPIO_RegDef_T *port);
void GPIO_Lock(GPIO_RegDef_T *port, uint8_t pin);




#endif
