#include "NVIC_driver.h"

/*This function enables the Interrupt for the supplied IRQ Number*/
void NVIC_EnableIRQ(uint8_t IRQn){
	NVIC_ISERx_BASE[IRQn/32] = (1 << (IRQn %32));
}

/*This function Disables the Interrupt for the supplied IRQ Number*/
void NVIC_DisableIRQ(uint8_t IRQn){
	NVIC_ICERx_BASE[IRQn/32] = (1 << (IRQn %32));
}

/*This function Sets Pending Interrupt for the supplied IRQ Number*/
void NVIC_SetPendingIRQ(uint8_t IRQn){
	NVIC_ISPRx_BASE[IRQn/32] = (1 << (IRQn %32));
}

/*This function clears the Pending Interrupt for the supplied IRQ Number*/
void NVIC_ClearPendingIRQ(uint8_t IRQn){
	NVIC_ICPRx_BASE[IRQn/32] = (1 << (IRQn %32));
}

/*This function returns the status of the supplied IRQ Number*/
bool NVIC_ReadActiveIRQ(uint8_t IRQn){
	return (NVIC_IABRx_BASE[IRQn/32] & ( 1 << (IRQn %32)));
}

/*This function sets the priority level for the Interrupt number supplied*/
void NVIC_SetIRQPriority(uint8_t IRQn, uint8_t priority){
	NVIC_IPRx_BASE[IRQn] = (priority & 0x0F) << 4;
}
