/*
 * FLASH Driver Header File
 *
 * 1. Provides APIs for configuring the Flash interface.
 * 2. Used to configure Flash memory wait states.
 * 3. Flash latency is required when increasing the CPU clock frequency.
 * 4. Provides control over Flash cache and prefetch features.
 * 5. Keeps Flash configuration separate from RCC.
 * 6. Used during high-speed system clock initialization.
 */
#ifndef FLASH_DRIVER_H_
#define FLASH_DRIVER_H_

#include "stm32f412xG.h"

void FLASH_ConfigFor100MHz(void);
#endif /* FLASH_DRIVER_H_ */
