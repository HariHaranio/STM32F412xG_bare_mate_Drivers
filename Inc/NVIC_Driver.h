#ifndef NVIC_DRIVER_H_
#define NVIC_DRIVER_H_

#include "stm32f412xG.h"

#include "stdint.h"
#include "stdbool.h"

void NVIC_EnableIRQ(uint8_t IRQn);
void NVIC_DisableIRQ(uint8_t IRQn);
void NVIC_SetPendingIRQ(uint8_t IRQn);
void NVIC_ClearPendingIRQ(uint8_t IRQn);
bool NVIC_ReadActiveIRQ(uint8_t IRQn);
void NVIC_SetIRQPriority(uint8_t IRQn, uint8_t priority);


#endif /* NVIC_DRIVER_H_ */
