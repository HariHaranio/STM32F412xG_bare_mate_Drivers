#ifndef RCC_DRIVER_H
#define RCC_DRIVER_H

#include "stm32f412xG.h"

void RCC_EnableGPIO(GPIO_RegDef *port);
void RCC_DisableGPIO(GPIO_RegDef *port);
void RCC_Config_HSE_SystemClock(void);
#endif
