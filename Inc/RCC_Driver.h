#ifndef RCC_DRIVER_H
#define RCC_DRIVER_H

#include "stm32f412xG.h"
#include <stdint.h>

void RCC_Enable_GPIO(GPIO_RegDef_T *port);
void RCC_Disable_GPIO(GPIO_RegDef_T *port);
void RCC_Config_HSE_SystemClock(void);
void RCC_Enable_SYSCFG(void);

uint32_t RCC_Get_PCLK1(void);
uint32_t RCC_Get_PCLK2(void);

void RCC_Enable_USART(USART_RegDef_T *USARTx);
void RCC_Disable_USART(USART_RegDef_T *USARTx);

void RCC_Enable_I2C(I2C_RegDef_T *I2C_);
void RCC_Disable_I2C(I2C_RegDef_T *I2C_);

void RCC_Enable_TIM2(void);
void RCC_Disable_TIM2(void);

void RCC_Enable_ADC1(ADC_RegDef_T *ADCx);
void RCC_Disable_ADC1(ADC_RegDef_T *ADCx);


#endif
