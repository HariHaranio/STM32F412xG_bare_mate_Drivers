#ifndef SYSCONFIG_DRIVER_H_
#define SYSCONFIG_DRIVER_H_

#include "stm32f412xG.h"
#include "stdint.h"

void SYSCFG_SetEXTISource(uint8_t EXTILine, uint8_t EXTILineVal);


#endif /* SYSCONFIG_DRIVER_H_ */
