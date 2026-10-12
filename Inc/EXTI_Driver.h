#ifndef EXTI_DRIVER_H_
#define EXTI_DRIVER_H_

#include "stm32f412xG.h"
#include "stdint.h"
#include "stdbool.h"

typedef enum{
	EXTI_TRIGGER_RISING,
	EXTI_TRIGGER_FALLING,
	EXTI_TRIGGER_BOTH
}EXTI_TriggerType;

void EXTI_EnableInterrupt(uint8_t EXTILineNum, EXTI_TriggerType TriggerType);
void EXTI_EnableEvent(uint8_t EXTILineNum, EXTI_TriggerType TriggerType);
void EXTI_ClearPending(uint8_t EXTILineNum);
bool EXTI_IsPending(uint8_t EXTILineNum);

#endif /* EXTI_DRIVER_H_ */
