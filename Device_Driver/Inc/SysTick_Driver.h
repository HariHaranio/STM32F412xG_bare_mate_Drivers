#ifndef SYSTICK_DRIVER_H
#define SYSTICK_DRIVER_H

#include "stm32f412xG.h"

void SysTick_Init(void);
void SysTick_DelayMs(uint32_t delay);

#endif
