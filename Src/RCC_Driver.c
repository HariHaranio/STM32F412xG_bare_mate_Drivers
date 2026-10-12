#include "RCC_Driver.h"

/*Enables the GPIO Peripheral Clock for a particular GPIO port */
void RCC_EnableGPIO(GPIO_RegDef *port)
{
	if(port == GPIOA)
	{
		RCC->AHB1ENR |= ( 1 << 0);
	}
	else if (port == GPIOB)
	{
		RCC->AHB1ENR |= ( 1 << 1);
	}
	else if (port == GPIOC)
	{
		RCC->AHB1ENR |= ( 1 << 2);
	}
	else if (port == GPIOD)
	{
		RCC->AHB1ENR |= ( 1 << 3);
	}
	else if (port == GPIOE)
	{
		RCC->AHB1ENR |= ( 1 << 4);
	}
	else if (port == GPIOF)
	{
	    RCC->AHB1ENR |= (1 << 5);
	}
	else if (port == GPIOG)
	{
	    RCC->AHB1ENR |= (1 << 6);
	}
	else if (port == GPIOH)
	{
		RCC->AHB1ENR |= ( 1 << 7);
	}
}

/*Disables the GPIO Peripheral Clock for a particular GPIO port */
void RCC_DisableGPIO(GPIO_RegDef *port)
{
	if(port == GPIOA)
	{
		RCC->AHB1ENR &= ~( 1 << 0);
	}
	else if (port == GPIOB)
	{
		RCC->AHB1ENR &= ~( 1 << 1);
	}
	else if (port == GPIOC)
	{
		RCC->AHB1ENR &= ~( 1 << 2);
	}
	else if (port == GPIOD)
	{
		RCC->AHB1ENR &= ~( 1 << 3);
	}
	else if (port == GPIOE)
	{
		RCC->AHB1ENR &= ~( 1 << 4);
	}
	else if (port == GPIOF)
	{
	    RCC->AHB1ENR &= ~(1 << 5);
	}
	else if (port == GPIOG)
	{
	    RCC->AHB1ENR &= ~(1 << 6);
	}
	else if (port == GPIOH)
	{
		RCC->AHB1ENR &= ~( 1 << 7);
	}
}

void RCC_Config_HSE_SystemClock(void)
{
	//Enable HSE Clock
	RCC->CR |= ( 1 << 16);

	//wait until HSE is ready
	while(!(RCC->CR & (1<<17)));

	//Select HSE as System Clock
	RCC->CFGR &= ~(0b11 << 0);
	RCC->CFGR |= (0b01 << 0);

	//wait until System Clock is set to HSE
//	while(!(RCC->CFGR & (0b01 << 2)));
	while ((RCC->CFGR & (0b11 << 2)) != (0b01 << 2));
}

