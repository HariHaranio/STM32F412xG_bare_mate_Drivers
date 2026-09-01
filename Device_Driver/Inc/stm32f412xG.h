#ifndef STM32F412XG_H
#define STM32F412XG_H

#include "stdint.h"

/* =========================================================
 * Peripheral Base Addresses
 * ========================================================= */

#define AHB1PERIPH_BASEADDR    0x40020000U


/* =========================================================
 * RCC
 * ========================================================= */

#define RCC_BASEADDR           0x40023800U


/* =========================================================
 * GPIO Base Addresses
 * ========================================================= */

#define GPIOA_BASEADDR          (AHB1PERIPH_BASEADDR + 0x0000U)
#define GPIOB_BASEADDR          (AHB1PERIPH_BASEADDR + 0x0400U)
#define GPIOC_BASEADDR          (AHB1PERIPH_BASEADDR + 0x0800U)
#define GPIOD_BASEADDR          (AHB1PERIPH_BASEADDR + 0x0C00U)
#define GPIOE_BASEADDR        	(AHB1PERIPH_BASEADDR + 0x1000U)
#define GPIOF_BASEADDR    		(AHB1PERIPH_BASEADDR + 0x1400U)
#define GPIOG_BASEADDR			(AHB1PERIPH_BASEADDR + 0x1800U)
#define GPIOH_BASEADDR        	(AHB1PERIPH_BASEADDR + 0x1C00U)


/* =========================================================
 * GPIO Register Structure
 * ========================================================= */

typedef struct
{
    volatile uint32_t MODER;       /* Offset 0x00 */
    volatile uint32_t OTYPER;      /* Offset 0x04 */
    volatile uint32_t OSPEEDR;     /* Offset 0x08 */
    volatile uint32_t PUPDR;       /* Offset 0x0C */
    volatile uint32_t IDR;         /* Offset 0x10 */
    volatile uint32_t ODR;         /* Offset 0x14 */
    volatile uint32_t BSRR;        /* Offset 0x18 */
    volatile uint32_t LCKR;        /* Offset 0x1C */
    volatile uint32_t AFRL;        /* Offset 0x20 */
    volatile uint32_t AFRH;        /* Offset 0x24 */

} GPIO_RegDef;


/* =========================================================
 * RCC Register Structure
 * ========================================================= */

typedef struct
{
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;

    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;

    volatile uint32_t RESERVED1;
    volatile uint32_t RESERVED2;

    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;

    volatile uint32_t RESERVED3;
    volatile uint32_t RESERVED4;

    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;

    volatile uint32_t RESERVED5;
    volatile uint32_t RESERVED6;

    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;

    volatile uint32_t RESERVED7;
    volatile uint32_t RESERVED8;

    volatile uint32_t AHB1LPENR;
    volatile uint32_t AHB2LPENR;

    volatile uint32_t RESERVED9;
    volatile uint32_t RESERVED10;

    volatile uint32_t APB1LPENR;
    volatile uint32_t APB2LPENR;

    volatile uint32_t RESERVED11;
    volatile uint32_t RESERVED12;

    volatile uint32_t BDCR;
    volatile uint32_t CSR;

    volatile uint32_t RESERVED13;
    volatile uint32_t RESERVED14;

    volatile uint32_t SSCGR;
    volatile uint32_t PLLI2SCFGR;

    volatile uint32_t RESERVED15;

    volatile uint32_t DCKCFGR;

} RCC_RegDef;


/* =========================================================
 * GPIO Peripheral Pointers
 * ========================================================= */

#define GPIOA    ((GPIO_RegDef *)GPIOA_BASEADDR)
#define GPIOB    ((GPIO_RegDef *)GPIOB_BASEADDR)
#define GPIOC    ((GPIO_RegDef *)GPIOC_BASEADDR)
#define GPIOD    ((GPIO_RegDef *)GPIOD_BASEADDR)
#define GPIOE    ((GPIO_RegDef *)GPIOE_BASEADDR)
#define GPIOF    ((GPIO_RegDef *)GPIOF_BASEADDR)
#define GPIOG    ((GPIO_RegDef *)GPIOG_BASEADDR)
#define GPIOH    ((GPIO_RegDef *)GPIOH_BASEADDR)


/* =========================================================
 * RCC Peripheral Pointer
 * ========================================================= */

#define RCC      ((RCC_RegDef *)RCC_BASEADDR)

#define SYSTICK_BASE    0xE000E010UL
/* =========================================================
 * GPIO Bit Masks & GPIO Shift Values
 * ========================================================= */

#define GPIO_MODER_BITMASK 		0x3
#define GPIO_OSPEEDR_BITMASK    0x3
#define GPIO_PUPDR_BITMASK		0x3
#define GPIO_AFR_MASK     	 	0xF
#define GPIO_MODER_SHIFT_BITS 	0x2
#define GPIO_OSPEEDR_SHIFT_BITS 0x2
#define GPIO_PUPDR_SHIFT_BITS 	0x2
#define GPIO_AFR_SIZE      		0x8
#define GPIO_AFR_MAXSIZE   		0xf
#define GPIO_AFR_SHIFT_BITS 	0x4

/* =====================================================
   SYSTICK
   ===================================================== */

#define SYSTICK_CTRL    (*(volatile unsigned int *)(SYSTICK_BASE + 0x00UL))
#define SYSTICK_LOAD    (*(volatile unsigned int *)(SYSTICK_BASE + 0x04UL))
#define SYSTICK_VAL     (*(volatile unsigned int *)(SYSTICK_BASE + 0x08UL))
#endif
