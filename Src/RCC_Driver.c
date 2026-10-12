#include "RCC_Driver.h"
#include "FLASH_Driver.h"
#include "PWR_Driver.h"

#define SYSTEM_CLOCK_HZ    100000000UL

/*Enables the GPIO Peripheral Clock for a particular GPIO port */
void RCC_Enable_GPIO(GPIO_RegDef_T *port)
{
	if(port == GPIOA)
	{
		RCC->AHB1ENR |= GPIOA_EN;
	}

	else if (port == GPIOB){
		RCC->AHB1ENR |= GPIOB_EN;
	}

	else if (port == GPIOC){
		RCC->AHB1ENR |= GPIOC_EN;
	}

	else if (port == GPIOD){
		RCC->AHB1ENR |= GPIOD_EN;
	}

	else if (port == GPIOE){
		RCC->AHB1ENR |= GPIOE_EN;
	}

	else if (port == GPIOF){
	    RCC->AHB1ENR |= GPIOF_EN;
	}

	else if (port == GPIOG){
	    RCC->AHB1ENR |= GPIOG_EN;
	}

	else if (port == GPIOH){
		RCC->AHB1ENR |= GPIOH_EN;
	}
}

/*Disables the GPIO Peripheral Clock for a particular GPIO port */
void RCC_Disable_GPIO(GPIO_RegDef_T *port){
	if(port == GPIOA){
		RCC->AHB1ENR &= ~GPIOA_EN;
	}

	else if (port == GPIOB){
		RCC->AHB1ENR &= ~GPIOB_EN;
	}

	else if (port == GPIOC){
		RCC->AHB1ENR &= ~GPIOC_EN;
	}

	else if (port == GPIOD){
		RCC->AHB1ENR &= ~GPIOD_EN;
	}

	else if (port == GPIOE){
		RCC->AHB1ENR &= ~GPIOE_EN;
	}

	else if (port == GPIOF){
	    RCC->AHB1ENR &= ~GPIOF_EN;
	}

	else if (port == GPIOG){
	    RCC->AHB1ENR &= ~GPIOG_EN;
	}

	else if (port == GPIOH){
		RCC->AHB1ENR &= ~GPIOH_EN;
	}
}


void RCC_Config_HSE_SystemClock(void){
    /* Configure Power voltage scaling */
    PWR_SetVoltageScale1();

    /* Configure Flash for 100 MHz */
    FLASH_ConfigFor100MHz();
    // 1. Enable HSE
    RCC->CR |= HSE_ON;

    // 2. Wait until HSE is ready
    while (!(RCC->CR & HSE_RDY));

    // 3. Configure PLL
    // PLLM = 4
    // PLLN = 100
    // PLLP = 2
    // PLLSRC = HSE

    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLM_MASK;
    RCC->PLLCFGR |=  RCC_PLLCFGR_PLLM_DIV4;              // PLLM = 4

    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLN_MASK;
    RCC->PLLCFGR |=  RCC_PLLCFGR_PLLN_MUL100;            // PLLN = 100

    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLP_MASK;
    RCC->PLLCFGR |=  RCC_PLLCFGR_PLLP_DIV2;          // PLLP = 2

    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLSRC_MASK;
    RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSE;             // PLLSRC = HSE

    // 4. Configure AHB
    // AHB = SYSCLK / 1
    RCC->CFGR &= ~RCC_CFGR_HPRE_MASK;
    RCC->CFGR |=  RCC_CFGR_HPRE_DIV1;

    // 5. Configure APB1
    // APB1 = HCLK / 2
    RCC->CFGR &= ~RCC_CFGR_PPRE1_MASK;
    RCC->CFGR |=  RCC_CFGR_PPRE1_DIV2;

    // 6. Configure APB2
    // APB2 = HCLK / 1
    RCC->CFGR &= ~RCC_CFGR_PPRE2_MASK;
    RCC->CFGR |=  RCC_CFGR_PPRE2_DIV1;

    // 7. Enable PLL
    RCC->CR |= RCC_CR_PLLON;

    // 8. Wait until PLL is ready
    while (!(RCC->CR & RCC_CR_PLLRDY));

    // 9. Select PLL as System Clock
    RCC->CFGR &= ~RCC_CFGR_SW_MASK;
    RCC->CFGR |=  RCC_CFGR_SW_PLL;

    // 10. Wait until PLL is selected
    while ((RCC->CFGR & RCC_CFGR_SWS_MASK) != RCC_CFGR_SWS_PLL);
}

void RCC_Enable_SYSCFG(void){ RCC->APB2ENR |= SYSCFG_EN; }
/*
 *                  HSE
                 8 MHz
                   │
                   ▼
              ┌─────────┐
              │   PLL   │
              │ M = 4   │
              │ N = 100 │
              │ P = 2   │
              └────┬────┘
                   │
                100 MHz
                   │
                 SYSCLK
                   │
              ┌────┴────┐
              │         │
             AHB       APB
              │         │
           100 MHz      │
              │         │
             HCLK       ├── APB1 /2 → 50 MHz
                        │
                        └── APB2 /1 → 100 MHz

                        */
uint32_t RCC_Get_PCLK1(void){
    uint32_t hclk;
    uint32_t pclk1;
    uint32_t hpre;
    uint32_t ppre1;

    hpre = (RCC->CFGR & RCC_CFGR_HPRE_MASK_PCLK1) / RCC_CFGR_HPRE_DIV1_PCLK1;

    if (hpre < RCC_CFGR_HPRE_DIV2_ENCODING){
        hclk = SYSTEM_CLOCK_HZ;
    }else{
        hclk = SYSTEM_CLOCK_HZ / (1 << (hpre - 7));
    }

    ppre1 = (RCC->CFGR & RCC_CFGR_PPRE1_MASK_PCLK1) / RCC_CFGR_PPRE1_DIV1_PCLK1;

    if (ppre1 < RCC_CFGR_PPRE_DIV2_ENCODING){
        pclk1 = hclk;
    }else {
        pclk1 = hclk / (1 << (ppre1 - 3));
    }

    return pclk1;
}

uint32_t RCC_Get_PCLK2(void){
    uint32_t hclk;
    uint32_t pclk2;
    uint32_t hpre;
    uint32_t ppre2;

//    hpre = (RCC->CFGR & (0x0F << 4)) / (1 << 4);
    hpre = (RCC->CFGR & RCC_CFGR_HPRE_MASK_PCLK2) / RCC_CFGR_HPRE_DIV1_PCLK2;

    if (hpre < RCC_CFGR_HPRE_DIV2_ENCODING){
        hclk = SYSTEM_CLOCK_HZ;
    }else{
        hclk = SYSTEM_CLOCK_HZ / (1 << (hpre - 7));
    }

    ppre2 = (RCC->CFGR & RCC_CFGR_PPRE2_MASK_PCLK2) / RCC_CFGR_PPRE2_DIV1_PCLK2;

    if (ppre2 < RCC_CFGR_PPRE_DIV2_ENCODING){
        pclk2 = hclk;
    }else{
        pclk2 = hclk / (1 << (ppre2 - 3));
    }

    return pclk2;
}


void RCC_Enable_USART(USART_RegDef_T *USARTx){
    if (USARTx == USART1){
        RCC->APB2ENR |= USART_EN_1;

    }else if (USARTx == USART6){
        RCC->APB2ENR |= USART_EN_6;

    }else if (USARTx == USART2){
        RCC->APB1ENR |= USART_EN_2;

    }else if (USARTx == USART3){
        RCC->APB1ENR |= USART_EN_3;
    }
}


void RCC_Disable_USART(USART_RegDef_T *USARTx){
    if (USARTx == USART1){
        RCC->APB2ENR &= ~USART_EN_1;

    }else if (USARTx == USART6){
        RCC->APB2ENR &= ~USART_EN_6;

    }else if (USARTx == USART2){
        RCC->APB1ENR &= ~USART_EN_2;

    }else if (USARTx == USART3){
        RCC->APB1ENR &= ~USART_EN_3;
    }
}


void RCC_Enable_I2C(I2C_RegDef_T *I2Cx)
{
    if(I2Cx == I2C_1){
        RCC->APB1ENR |= I2C_EN_1;
    }

    else if(I2Cx == I2C_2){
        RCC->APB1ENR |= I2C_EN_2;
    }

    else if(I2Cx == I2C_3){
        RCC->APB1ENR |= I2C_EN_3;
    }

    else if(I2Cx == I2CFMP1){
        RCC->APB1ENR |= I2C_EN_FMP1;
    }
}

void RCC_Disable_I2C(I2C_RegDef_T *I2Cx){
    if(I2Cx == I2C_1){
        RCC->APB1ENR &= ~I2C_EN_1;
    }

    else if(I2Cx == I2C_2){
        RCC->APB1ENR &= ~I2C_EN_2;
    }

    else if(I2Cx == I2C_3){
        RCC->APB1ENR &= ~I2C_EN_3;
    }

    else if(I2Cx == I2CFMP1){
        RCC->APB1ENR &= ~I2C_EN_FMP1;
    }
}

void RCC_Enable_TIM2(void)	{

	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
}

void RCC_Disable_TIM2(void)	{

	RCC->APB1ENR &= ~RCC_APB1ENR_TIM2EN;
}

void RCC_Enable_ADC1(ADC_RegDef_T *ADCx)	{

	if(ADCx == ADC1){
		RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	}
}
void RCC_Disable_ADC1(ADC_RegDef_T *ADCx){

	if(ADCx == ADC1){
		RCC->APB2ENR &= ~RCC_APB2ENR_ADC1EN;
	}

}
