#include "SYSCONFIG_Driver.h"

/* This function accepts two inputs and configures the SYSCFG_EXTICRx Register*/
void SYSCFG_SetEXTISource(uint8_t EXTILine, uint8_t EXTILineVal){
	uint8_t regIndex;
	uint8_t bitPos;

	/*EXTILine will be between 0 and 15*/
	regIndex = EXTILine / 4;
	bitPos = (EXTILine % 4 )* 4;

	/*Clear all the relevant bits*/
	SYSCFG->EXTICR[regIndex] &= ~(0xF << bitPos);

	/*Set the relvant bits*/
 	SYSCFG->EXTICR[regIndex] |= (EXTILineVal & 0x0F) << bitPos;
}
