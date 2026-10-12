#include "EXTI_Driver.h"

/*This function enables the Interrupt of EXTI by unmasking the IMR Register*/
void EXTI_EnableInterrupt(uint8_t EXTILineNum, EXTI_TriggerType TriggerType){
	EXTI->IMR |= (1 << EXTILineNum);

	switch(TriggerType){
		case EXTI_TRIGGER_RISING:
			EXTI->RTSR |= (1 << EXTILineNum);
			EXTI->FTSR &= ~(1 << EXTILineNum);
			break;
		case EXTI_TRIGGER_FALLING:
			EXTI->FTSR |= (1 << EXTILineNum);
			EXTI->RTSR &= ~(1 << EXTILineNum);
			break;
		case EXTI_TRIGGER_BOTH:
			EXTI->RTSR |= (1 << EXTILineNum);
			EXTI->FTSR |= (1 << EXTILineNum);
			break;
		default:
			break;
	}
}

/*This function enables the Event of EXTI by unmasking the EMR Register*/
void EXTI_EnableEvent(uint8_t EXTILineNum, EXTI_TriggerType TriggerType){
	EXTI->EMR |= (1 << EXTILineNum);

	switch(TriggerType){
		case EXTI_TRIGGER_RISING:
			EXTI->RTSR |= (1 << EXTILineNum);
			EXTI->FTSR &= ~(1 << EXTILineNum);
			break;
		case EXTI_TRIGGER_FALLING:
			EXTI->FTSR |= (1 << EXTILineNum);
			EXTI->RTSR &= ~(1 << EXTILineNum);
			break;
		case EXTI_TRIGGER_BOTH:
			EXTI->RTSR |= (1 << EXTILineNum);
			EXTI->FTSR |= (1 << EXTILineNum);
			break;
		default:
			break;
	}
}


/*This function clears the pending bit in the PR Register for a paricular EXTI Line*/
void EXTI_ClearPending(uint8_t EXTILineNum){
	EXTI->PR |= ( 1<< EXTILineNum);
}

/*This function returns the pending status of the particular EXTI Line*/
bool EXTI_IsPending(uint8_t EXTILineNum){
	return (EXTI->PR & ( 1<< EXTILineNum)) ? 1:0;
}
