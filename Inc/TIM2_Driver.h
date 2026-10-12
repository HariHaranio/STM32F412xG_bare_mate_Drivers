#ifndef TIM2_DRIVER_H_
#define TIM2_DRIVER_H_

#include "stm32f412xG.h"
#include "RCC_Driver.h"
#include <stdint.h>


typedef struct
{
    uint32_t TIM2_Prescaler;
    uint32_t TIM2_AutoReload;

} TIM2_Config_T;


void TIM2_Init(TIM2_Config_T *TIM2_Config);

void TIM2_Start(void);

void TIM2_Stop(void);

void TIM2_EnableInterrupt(void);

void TIM2_DisableInterrupt(void);

void TIM2_ClearUpdateFlag(void);

uint32_t TIM2_GetTick(void);
void TIM2_DelayMs(uint32_t delay);
void TIM2_DelayUs(uint32_t us);

#endif /* TIM2_DRIVER_H_ */
