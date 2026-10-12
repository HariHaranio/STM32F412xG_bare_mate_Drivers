/*
 * PWR Driver Header File
 *
 * 1. Provides APIs for configuring the STM32F412 power control.
 * 2. Used to configure the voltage scaling of the MCU.
 * 3. Voltage scaling is required for high-frequency operation.
 * 4. Provides control over the Power Control peripheral.
 * 5. Keeps power-related configuration separate from RCC.
 * 6. Used during system clock initialization.
 */

#ifndef PWR_DRIVER_H_
#define PWR_DRIVER_H_

#include "stm32f412xG.h"

void PWR_SetVoltageScale1(void);

#endif /* PWR_DRIVER_H_ */
