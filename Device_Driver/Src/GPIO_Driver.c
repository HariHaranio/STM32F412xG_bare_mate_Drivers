#include "GPIO_Driver.h"


/*This function Initializes the GPIO Port Pin*/
void GPIO_Init(GPIO_RegDef *port, GPIO_PINCONFIG_T *pinConfig)
{
	uint8_t pin = pinConfig->pin;

	port->MODER &= ~(GPIO_MODER_BITMASK << (GPIO_MODER_SHIFT_BITS * pin));
	port->MODER |= ((pinConfig->mode & GPIO_MODER_BITMASK) << (GPIO_MODER_SHIFT_BITS * pin));

	port->OTYPER &= ~(1 << pin);
	port->OTYPER  |= (pinConfig->otype << pin);

	port->OSPEEDR &= ~(GPIO_OSPEEDR_BITMASK << (GPIO_OSPEEDR_SHIFT_BITS * pin));
	port->OSPEEDR |= ((pinConfig->speed & GPIO_OSPEEDR_BITMASK) << (GPIO_OSPEEDR_SHIFT_BITS * pin));

	port->PUPDR &= ~(GPIO_PUPDR_BITMASK << (GPIO_PUPDR_SHIFT_BITS * pin));
	port->PUPDR |= ((pinConfig->pupdr & GPIO_PUPDR_BITMASK) << (GPIO_PUPDR_SHIFT_BITS *pin));

	if(pinConfig->mode == GPIO_MODE_ALT)
	{
		if(pin < GPIO_AFR_SIZE)
		{
			port->AFRL &= ~(GPIO_AFR_MASK << (GPIO_AFR_SHIFT_BITS*pin));
			port->AFRL |= ((pinConfig->alternatefunc & GPIO_AFR_MASK) << (GPIO_AFR_SHIFT_BITS * pin));
		}
		else if(pin >= GPIO_AFR_SIZE || pin <=GPIO_AFR_MAXSIZE)
		{
			port->AFRH &= ~(GPIO_AFR_MASK << (GPIO_AFR_SHIFT_BITS*(pin-GPIO_AFR_SIZE)));
			port->AFRH |= ((pinConfig->alternatefunc & GPIO_AFR_MASK) << (GPIO_AFR_SHIFT_BITS * (pin-GPIO_AFR_SIZE)));
		}
	}
}

/*This function DeInitializes the GPIO Port Pin*/
void GPIO_DeInit_Pin(GPIO_RegDef *port,GPIO_PINCONFIG_T *pinConfig)
{
	uint8_t pin = pinConfig->pin;

	port->MODER &= ~(GPIO_MODER_BITMASK << (GPIO_MODER_SHIFT_BITS * pin));
	port->OTYPER &= ~(1 << pin);
	port->OSPEEDR &= ~(GPIO_OSPEEDR_BITMASK << (GPIO_OSPEEDR_BITMASK * pin));
	port->PUPDR &= ~(GPIO_PUPDR_BITMASK << (GPIO_PUPDR_BITMASK * pin));
	if(pinConfig->mode == GPIO_MODE_ALT)
	{
		if(pin < GPIO_AFR_SIZE)
		{
			port->AFRL &= ~(GPIO_AFR_MASK << (GPIO_AFR_SHIFT_BITS*pin));
		}
		else
		{
			port->AFRH &= ~(GPIO_AFR_MASK << (GPIO_AFR_SHIFT_BITS*pin));
		}
	}
}

void GPIO_DeInit(GPIO_RegDef *port)
{
	/*Reset the AHB1RSTR GPIO Specific bit*/

	if(port == GPIOA)
	{
		RCC->AHB1RSTR |= ( 1 << 0);
		RCC->AHB1RSTR &= ~( 1 << 0);
	}
	else if (port == GPIOB)
	{
		RCC->AHB1RSTR |= ( 1 << 1);
		RCC->AHB1RSTR &= ~( 1 << 1);
	}
	else if (port == GPIOC)
	{
		RCC->AHB1RSTR |= ( 1 << 2);
		RCC->AHB1RSTR &= ~( 1 << 2);
	}
	else if (port == GPIOD)
	{
		RCC->AHB1RSTR |= ( 1 << 3);
		RCC->AHB1RSTR &= ~( 1 << 3);
	}
	else if (port == GPIOF)
	{
	    RCC->AHB1RSTR |= (1 << 5);
	    RCC->AHB1RSTR &= ~(1 << 5);
	}
	else if (port == GPIOG)
	{
	    RCC->AHB1RSTR |= (1 << 6);
	    RCC->AHB1RSTR &= ~(1 << 6);
	}
	else if (port == GPIOE)
	{
		RCC->AHB1RSTR |= ( 1 << 4);
		RCC->AHB1RSTR &= ~( 1 << 4);
	}
	else if (port == GPIOH)
	{
		RCC->AHB1RSTR |= ( 1 << 7);
		RCC->AHB1RSTR &= ~( 1 << 7);
	}
}
/*This function toggles a particular GPIO Pin*/
void GPIO_TogglePin(GPIO_RegDef *port, uint8_t pin)
{
     port->ODR ^= (1 << pin);
}

/*This function Sets a particular GPIO Pin*/
void GPIO_SetPin(GPIO_RegDef *port, uint8_t pin)
{
	port->ODR |= ( 1 << pin);
}

/*This function Sets a particular GPIO Pin*/
void GPIO_ResetPin(GPIO_RegDef *port, uint8_t pin)
{
    port->ODR &= ~(1 << pin);
}
/*This function reads a particular GPIO Pin*/
uint8_t GPIO_ReadPin(GPIO_RegDef *port, uint8_t pin)
{
	return (port->IDR & ( 1 << pin));
}

/*This function Writes to a particular GPIO Port*/
void GPIO_WritePort(GPIO_RegDef *port, uint32_t portVal)
{
	port->ODR |= portVal;
}

/*This function Reads a particular GPIO Port*/
uint32_t GPIO_ReadPort(GPIO_RegDef *port)
{
	return port->IDR;
}

/*This function locks a particular GPIO Pin*/
void GPIO_Lock(GPIO_RegDef *port, uint8_t pin)
{

}
