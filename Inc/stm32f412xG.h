/**
 * @file    stm32f412xg.h
 * @brief   Register definitions and memory mapping for the STM32F412xG.
 *
 * @details This header defines memory addresses, peripheral base addresses,
 *          peripheral register mappings, and register-layout structures used
 *          by the STM32F412xG bare-metal driver library.
 *
 *          Register bit positions, masks, and field encodings are included
 *          from stm32f412xg_macros.h.
 *
 * @note    The definitions are based on the supplied header content.
 *          Hardware addresses, register offsets, memory boundaries, and
 *          peripheral layouts have not been independently verified here.
 *          Confirm them against the STM32F412xG data sheet and reference
 *          manual before using this header in production firmware.
 *
 * @author  Hariharan.io
 * @version 1.0
 * @date    2026
 */

#ifndef STM32F412XG_H
#define STM32F412XG_H

#include <stdint.h>
#include "stm32f412xg_macros.h"



/*brief  Macros related to all peripheral address, sram, flash address
 *@note  Data structures related to peripherals
 * 		 Peripherals bit definitions*/

#define FLASH_BASE_ADRR  				    0x08000000U
#define FLASH_END_ADDR       			    0x0807FFFFU
#define SYSMEM_BASE_ADDR     			    0x1FFF0000U
#define OPTBYTES_BASE_ADDR   			    0x1FFFC000U
#define SRAM_BASE_ADDR					    0x20000000U
#define SRAM_END_ADDR					    0x20020000U

/*@brief  BASE ADDRESS RELATED TO THE REGISTERS
 *@note   Used to Type cast to a pointer to Base address
 * */
#define APB1PERIPH_BASE_ADDR              	0x40000000U  /* APB1 peripheral bus base address */
#define APB2PERIPH_BASE_ADDR             	0x40007400U  /* APB2 peripheral bus base address */
#define AHB1PERIPH_BASE_ADDR              	0x40020000U  /* AHB1 peripheral bus base address */
#define AHB2PERIPH_BASE_ADDR              	0x50000000U  /* AHB2 peripheral bus base address */
#define FLASH_INTRFACE_REG_BASE_ADDR      	0x40023C00U  /* Flash interface register base address */
#define PWR_BASE_ADDR                      	0x40007000U  /* PWR peripheral base address */
#define RCC_BASE_ADDR                     	0x40023800U  /* RCC peripheral base address */
#define SYSCFG_BASE_ADDR                 	0x40013800U  /* SYSCFG peripheral base address */
#define EXTI_BASE_ADDR                    	0x40013C00U  /* EXTI peripheral base address */
#define SYSTICK_BASE_ADDR                	0xE000E010U /* SysTick register base address */
#define NVIC_BASE_ADDR                   	0xE000E100U  /* NVIC register base address */
#define USART1_BASE_ADDR                 	0x40011000U  /* USART1: APB2 */
#define USART2_BASE_ADDR                 	0x40004400U  /* USART2: APB1 */
#define USART3_BASE_ADDR                 	0x40004800U  /* USART3: APB1 */
#define USART6_BASE_ADDR                 	0x40011400U  /* USART6: APB2 */
#define I2C1_BASE_ADDR                   	0x40005400U  /* I2C1: APB1 */
#define I2C2_BASE_ADDR                   	0x40005800U  /* I2C2: APB1 */
#define I2C3_BASE_ADDR                   	0x40005C00U  /* I2C3: APB1 */
#define I2CFMP1_BASE_ADDR                	0x40006000U  /* I2C Fast-Mode Plus */
#define TIM2_BASE_ADDR                    	0x40000000U  /* TIM2 peripheral base address */
#define ADC1_BASE_ADDR                    	0x40012000U  /* ADC1 peripheral base address */


/*@brief Peripheral Related Structure declaration
 *@note  Peripheral Register Mapping Macro (a preprocessor macro using a pointer type cast).
 *
 * */
/* GPIO peripheral base addresses */
#define GPIOA_BASE_ADDR                      (AHB1PERIPH_BASE_ADDR + 0x0000U)      /* GPIOA base address */
#define GPIOB_BASE_ADDR                      (AHB1PERIPH_BASE_ADDR + 0x0400U)      /* GPIOB base address */
#define GPIOC_BASE_ADDR                      (AHB1PERIPH_BASE_ADDR + 0x0800U)      /* GPIOC base address */
#define GPIOD_BASE_ADDR                      (AHB1PERIPH_BASE_ADDR + 0x0C00U)      /* GPIOD base address */
#define GPIOE_BASE_ADDR                      (AHB1PERIPH_BASE_ADDR + 0x1000U)      /* GPIOE base address */
#define GPIOF_BASE_ADDR                      (AHB1PERIPH_BASE_ADDR + 0x1400U)      /* GPIOF base address */
#define GPIOG_BASE_ADDR                      (AHB1PERIPH_BASE_ADDR + 0x1800U)      /* GPIOG base address */
#define GPIOH_BASE_ADDR                      (AHB1PERIPH_BASE_ADDR + 0x1C00U)      /* GPIOH base address */

#define RCC                    				((RCC_RegDef_T *)RCC_BASE_ADDR)       /* RCC peripheral register mapping */
/* GPIO peripheral register mappings */
#define GPIOA                               ((GPIO_RegDef_T *)GPIOA_BASE_ADDR)    /* GPIOA register mapping */
#define GPIOB                               ((GPIO_RegDef_T *)GPIOB_BASE_ADDR)    /* GPIOB register mapping */
#define GPIOC                               ((GPIO_RegDef_T *)GPIOC_BASE_ADDR)    /* GPIOC register mapping */
#define GPIOD                               ((GPIO_RegDef_T *)GPIOD_BASE_ADDR)    /* GPIOD register mapping */
#define GPIOE                               ((GPIO_RegDef_T *)GPIOE_BASE_ADDR)    /* GPIOE register mapping */
#define GPIOF                               ((GPIO_RegDef_T *)GPIOF_BASE_ADDR)    /* GPIOF register mapping */
#define GPIOG                               ((GPIO_RegDef_T *)GPIOG_BASE_ADDR)    /* GPIOG register mapping */
#define GPIOH                               ((GPIO_RegDef_T *)GPIOH_BASE_ADDR)    /* GPIOH register mapping */

/* I2C peripheral register mappings */
#define I2C_1                               ((I2C_RegDef_T *)I2C1_BASE_ADDR)     /* I2C1 register mapping */
#define I2C_2                               ((I2C_RegDef_T *)I2C2_BASE_ADDR)     /* I2C2 register mapping */
#define I2C_3                               ((I2C_RegDef_T *)I2C3_BASE_ADDR)     /* I2C3 register mapping */
#define I2CFMP1                             ((I2C_RegDef_T *)I2CFMP1_BASE_ADDR)  /* I2C Fast-Mode Plus register mapping */

/* Power and Flash peripheral register mappings */
#define PWR                                 ((PWR_RegDef_T *)PWR_BASE_ADDR)                      /* PWR register mapping */
#define FLASH                               ((FLASH_RegDef_T *)FLASH_INTRFACE_REG_BASE_ADDR)     /* Flash interface register mapping */

/* SysTick system timer register access */
#define SYSTICK_CTRL                        (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x00))  /* SysTick control and status register */
#define SYSTICK_LOAD                        (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x04))  /* SysTick reload value register */
#define SYSTICK_VAL                         (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x08))  /* SysTick current value register */
#define SYSTICK_CALIB                       (*(volatile uint32_t *)(SYSTICK_BASE_ADDR + 0x0C))  /* SysTick calibration value register */

/* System configuration and external interrupt register mappings */
#define SYSCFG                              ((SYSCFG_RegDef *)SYSCFG_BASE_ADDR)   /* SYSCFG register mapping */
#define EXTI                                ((EXTI_RegDef *)EXTI_BASE_ADDR)        /* EXTI register mapping */

/* NVIC interrupt controller register mappings */
#define NVIC_ISERx_BASE                     ((volatile uint32_t *)NVIC_BASE_ADDR) /* Interrupt Set-Enable Registers */
#define NVIC_ICERx_BASE                     ((volatile uint32_t *)0xE000E180U)    /* Interrupt Clear-Enable Registers */
#define NVIC_ISPRx_BASE                     ((volatile uint32_t *)0xE000E200U)    /* Interrupt Set-Pending Registers */
#define NVIC_ICPRx_BASE                     ((volatile uint32_t *)0xE000E280U)    /* Interrupt Clear-Pending Registers */
#define NVIC_IABRx_BASE                     ((volatile uint32_t *)0xE000E300U)    /* Interrupt Active Bit Registers */
#define NVIC_IPRx_BASE                      ((volatile uint8_t *)0xE000E400U)     /* Interrupt Priority Registers */

/* USART peripheral register mappings */
#define USART1                              ((USART_RegDef_T *)USART1_BASE_ADDR)  /* USART1 register mapping */
#define USART2                              ((USART_RegDef_T *)USART2_BASE_ADDR)  /* USART2 register mapping */
#define USART3                              ((USART_RegDef_T *)USART3_BASE_ADDR)  /* USART3 register mapping */
#define USART6                              ((USART_RegDef_T *)USART6_BASE_ADDR)  /* USART6 register mapping */

/* Timer and ADC peripheral register mappings */
#define TIM2                                ((TIM_RegDef_T *)TIM2_BASE_ADDR)       /* TIM2 register mapping */
#define ADC1                                ((ADC_RegDef_T *)ADC1_BASE_ADDR)       /* ADC1 register mapping */

/* System Control Block register access */
#define SCB_CPACR_ADDR                      (*(volatile uint32_t *)0xE000ED88U)   /* Coprocessor Access Control Register */



/**
 * @brief   Peripheral register structure forward declarations.
 *
 * @details This section declares structure tags for the peripheral register
 *          definitions used by the STM32F412xG bare-metal driver library.
 *
 *          The declarations cover the following peripherals:
 *          - GPIO   : General-purpose input/output.
 *          - RCC    : Reset and clock control.
 *          - PWR    : Power control.
 *          - FLASH  : Flash memory interface.
 *          - SYSCFG : System configuration controller.
 *          - EXTI   : External interrupt/event controller.
 *          - USART  : Universal synchronous/asynchronous receiver-transmitter.
 *          - ADC    : Analog-to-digital converter.
 *
 * @note    These are forward declarations only. They declare the structure tags
 *          but do not define the register layout or allocate memory.
 *
 *
 */
struct GPIO_RegDef_T;
struct RCC_RegDef_T;
struct PWR_RegDef_T;
struct FLASH_RegDef_T;
struct SYSCFG_RegDef;
struct EXTI_RegDef;
struct USART_RegDef_T;
struct ADC_RegDef_T;


typedef struct{
	Reg32_T MODER;       /* Offset 0x00 */
    Reg32_T OTYPER;      /* Offset 0x04 */
    Reg32_T OSPEEDR;     /* Offset 0x08 */
    Reg32_T PUPDR;       /* Offset 0x0C */
    Reg32_T IDR;         /* Offset 0x10 */
    Reg32_T ODR;         /* Offset 0x14 */
    Reg32_T BSRR;        /* Offset 0x18 */
    Reg32_T LCKR;        /* Offset 0x1C */
    Reg32_T AFRL;        /* Offset 0x20 */
    Reg32_T AFRH;        /* Offset 0x24 */
} GPIO_RegDef_T;

typedef struct{
    Reg32_T CR;
    Reg32_T PLLCFGR;
    Reg32_T CFGR;
    Reg32_T CIR;
    Reg32_T AHB1RSTR;
    Reg32_T AHB2RSTR;
    Reg32_T RESERVED1;
    Reg32_T RESERVED2;
    Reg32_T APB1RSTR;
    Reg32_T APB2RSTR;
    Reg32_T RESERVED3;
    Reg32_T RESERVED4;
    Reg32_T AHB1ENR;
    Reg32_T AHB2ENR;
    Reg32_T RESERVED5;
    Reg32_T RESERVED6;
    Reg32_T APB1ENR;
    Reg32_T APB2ENR;
    Reg32_T RESERVED7;
    Reg32_T RESERVED8;
    Reg32_T AHB1LPENR;
    Reg32_T AHB2LPENR;
    Reg32_T RESERVED9;
    Reg32_T RESERVED10;
    Reg32_T APB1LPENR;
    Reg32_T APB2LPENR;
    Reg32_T RESERVED11;
    Reg32_T RESERVED12;
    Reg32_T BDCR;
    Reg32_T CSR;
    Reg32_T RESERVED13;
    Reg32_T RESERVED14;
    Reg32_T SSCGR;
    Reg32_T PLLI2SCFGR;
    Reg32_T RESERVED15;
    Reg32_T DCKCFGR;
} RCC_RegDef_T;

typedef struct{
	Reg32_T PWR_CR;
	Reg32_T PWR_CSR;
}PWR_RegDef_T;

typedef struct{
	Reg32_T FLASH_ACR;
	Reg32_T FLASH_KEYR;
	Reg32_T FLASH_OPTKEYR;
	Reg32_T FLASH_SR;
	Reg32_T FLASH_CR;
	Reg32_T FLASH_OPTCR;
}FLASH_RegDef_T;

/*SYSCONFIG Related Macros*/
typedef struct
{
	Reg32_T MEMRMP;      // Memory Remap Register
	Reg32_T PMC;		   // Peripheral Mode Config Register
	Reg32_T EXTICR[4];   // External Interrupt Config Register
	Reg32_T RESERVED[2]; // Reserved Registers
	Reg32_T CMPCR; 	   // Compensation Cell Control Register
}SYSCFG_RegDef;


/*EXTI Register Stuct*/
typedef struct
{
	Reg32_T IMR;		/*Interrupt Mask Register*/
	Reg32_T EMR;		/*Event Mask Register*/
	Reg32_T RTSR;		/*Rising Trigger Selection Register*/
	Reg32_T FTSR;		/*Falling Trigger Selection Register*/
	Reg32_T SWIER;		/*Software Interrupt Event Register*/
	Reg32_T PR;			/*Pending Register*/
}EXTI_RegDef;

/*Register Structure for UART*/
typedef struct{

	Reg32_T SR;
	Reg32_T DR;
	Reg32_T BRR;
	Reg32_T CR1;
	Reg32_T CR2;
	Reg32_T CR3;
	Reg32_T GTPR;

}USART_RegDef_T;

typedef struct{

	Reg32_T I2C_CR1;		// I2C control register 1 (I2C_CR1)
	Reg32_T I2C_CR2;		// I2C control register 2 (I2C_CR2)
	Reg32_T I2C_OAR1;		// I2C own address register 1 (I2C_OAR1)
	Reg32_T I2C_OAR2;		// I2C own address register 2 (I2C_OAR2)
	Reg32_T I2C_DR;			// I2C data register (I2C_DR)
	Reg32_T I2C_SR1;		// I2C status register 1 (I2C_SR1)
	Reg32_T I2C_SR2;		// I2C status register 2 (I2C_SR2)
	Reg32_T I2C_CCR;		// I2C clock control registe r (I2C_CCR)
	Reg32_T I2C_TRISE;		// I2C TRISE register (I2C_TRISE)
	Reg32_T I2C_FLTR;		// I2C FLTR register (I2C_FLTR)

}I2C_RegDef_T;

typedef struct
{
    Reg32_T TIMx_CR1;       // 0x00
    Reg32_T TIMx_CR2;       // 0x04
    Reg32_T TIMx_SMCR;      // 0x08
    Reg32_T TIMx_DIER;      // 0x0C
    Reg32_T TIMx_SR;        // 0x10
    Reg32_T TIMx_EGR;       // 0x14
    Reg32_T TIMx_CCMR1;     // 0x18
    Reg32_T TIMx_CCMR2;     // 0x1C
    Reg32_T TIMx_CCER;      // 0x20
    Reg32_T TIMx_CNT;       // 0x24
    Reg32_T TIMx_PSC;       // 0x28
    Reg32_T TIMx_ARR;       // 0x2C
    Reg32_T RESERVED0;      // 0x30
    Reg32_T TIMx_CCR1;      // 0x34
    Reg32_T TIMx_CCR2;      // 0x38
    Reg32_T TIMx_CCR3;      // 0x3C
    Reg32_T TIMx_CCR4;      // 0x40
    Reg32_T RESERVED1;      // 0x44
    Reg32_T TIMx_DCR;       // 0x48
    Reg32_T TIMx_DMAR;      // 0x4C

} TIM_RegDef_T;


typedef struct {

	Reg32_T ADC_SR;
	Reg32_T ADC_CR1;
	Reg32_T ADC_CR2;
	Reg32_T ADC_SMPR1;
	Reg32_T ADC_SMPR2;
	Reg32_T ADC_JOFR1;
	Reg32_T ADC_JOFR2;
	Reg32_T ADC_JOFR3;
	Reg32_T ADC_JOFR4;
	Reg32_T ADC_HTR;
	Reg32_T ADC_LTR;
	Reg32_T ADC_SQR1;
	Reg32_T ADC_SQR2;
	Reg32_T ADC_SQR3;
	Reg32_T ADC_JSQR;
	Reg32_T ADC_JDR1;
	Reg32_T ADC_JDR2;
	Reg32_T ADC_JDR3;
	Reg32_T ADC_JDR4;
	Reg32_T ADC_DR;

}ADC_RegDef_T;

#endif
