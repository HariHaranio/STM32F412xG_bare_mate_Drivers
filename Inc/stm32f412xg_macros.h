/**
 * @file    stm32f412xg_macros.h
 * @brief   Register bit definitions and configuration macros for STM32F412xG.
 *
 * @details This header contains bit positions, masks, field encodings, peripheral
 *          clock-enable bits, interrupt numbers, and control flags used by the
 *          bare-metal peripheral drivers.
 *
 * @note    These definitions were documented from the supplied header content.
 *          Their hardware correctness has not been independently verified here;
 *          confirm register fields and encodings against the STM32F412xG reference
 *          manual before using them in production firmware.
 *
 * @author  Hariharan.io
 * @version 1.0
 * @date    2026
 *
*/

#ifndef STM32F412XG_MACROS_H_
#define STM32F412XG_MACROS_H_

typedef volatile uint32_t Reg32_T;
typedef volatile uint16_t Reg16_T;
typedef volatile uint8_t  Reg8_T;

/**
 * @brief   RCC peripheral clock-enable and oscillator control macros.
 *
 * @details This section defines bit masks used to enable peripheral clocks
 *          through the RCC registers and to control the High-Speed External
 *          (HSE) oscillator.
 *
 *          The macros cover the following peripherals and functions:
 *          - TIM2 clock enable through RCC_APB1ENR.
 *          - ADC clock enable through RCC_APB2ENR.
 *          - GPIO port clock enables for GPIOA through GPIOH.
 *          - USART peripheral clock enables for USART1, USART2, USART3,
 *            and USART6.
 *          - I2C peripheral clock enables for I2C1, I2C2, I2C3, and I2CFMP1.
 *          - SYSCFG peripheral clock enable.
 *          - HSE oscillator enable and ready-status flags.
 *
 * @note    These macros are based on the supplied definitions. Verify the
 *          register assignments and bit positions against the STM32F412xG
 *          reference manual before using them in production firmware.
 *
 */
#define RCC_APB1ENR_TIM2EN    		     (1U << 0) /* TIM2 Clock Enable */
#define RCC_APB2ENR_ADC1EN    		     (1U << 8) /* ADC1 Clock Enable */

#define GPIOA_EN						 (1 << 0U)
#define GPIOB_EN						 (1 << 1U)
#define GPIOC_EN						 (1 << 2U)
#define GPIOD_EN						 (1 << 3U)
#define GPIOE_EN						 (1 << 4U)
#define GPIOF_EN						 (1 << 5U)
#define GPIOG_EN						 (1 << 6U)
#define GPIOH_EN						 (1 << 7U)

#define USART_EN_1						 (1 << 4U)
#define USART_EN_2						 (1 << 17U)
#define USART_EN_3						 (1 << 18U)
#define USART_EN_6						 (1 << 5U)

#define I2C_EN_1						 (1 << 21U)
#define I2C_EN_2						 (1 << 22U)
#define I2C_EN_3						 (1 << 23U)
#define I2C_EN_FMP1						 (1 << 24U)

#define SYSCFG_EN						 (1 << 14U)

#define HSE_ON							 (1 << 16U)
#define HSE_RDY		 					 (1 << 17U)

/**
 * @brief   RCC clock configuration and prescaler macros.
 *
 * @details This section defines bit positions, masks, and configuration values
 *          used to configure the Reset and Clock Control (RCC) peripheral.
 *
 *          The macros cover the following settings:
 *          - PLLM: PLL input clock division factor.
 *          - PLLN: PLL multiplication factor.
 *          - PLLP: Main PLL division factor.
 *          - PLLSRC: PLL clock source selection.
 *          - HPRE: AHB clock prescaler configuration.
 *          - PPRE1: APB1 clock prescaler configuration.
 *          - PPRE2: APB2 clock prescaler configuration.
 *          - SW and SWS: System clock source selection and status.
 *          - PLLON and PLLRDY: Main PLL enable and ready flags.
 *          - Prescaler encodings for AHB, APB1, and APB2 clock configuration.
 *
 * @note    These macros are based on the supplied definitions. Verify register
 *          fields, bit positions, and encodings against the STM32F412xG
 *          reference manual before using them in production firmware.
 *
 * @warning The supplied definitions include multiple DIV1 prescaler macros
 *          that encode a value of 1 in the relevant field. Confirm these
 *          encodings before use; DIV1 is generally represented by a zero
 *          prescaler field value.

 * PLLM: PLL input clock division factor */
#define RCC_PLLCFGR_PLLM_POS              0U
#define RCC_PLLCFGR_PLLM_MASK             (0x3FU << RCC_PLLCFGR_PLLM_POS)
#define RCC_PLLCFGR_PLLM_DIV4             (0x4U << RCC_PLLCFGR_PLLM_POS)
/* PLLN: PLL multiplication factor */
#define RCC_PLLCFGR_PLLN_POS              6U
#define RCC_PLLCFGR_PLLN_MASK             (0x1FFU << RCC_PLLCFGR_PLLN_POS)
#define RCC_PLLCFGR_PLLN_MUL100           (100U << RCC_PLLCFGR_PLLN_POS)
/* PLLP: Main PLL division factor */
#define RCC_PLLCFGR_PLLP_POS              16U
#define RCC_PLLCFGR_PLLP_MASK             (0x3U << RCC_PLLCFGR_PLLP_POS)
#define RCC_PLLCFGR_PLLP_DIV2             (0x00U << RCC_PLLCFGR_PLLP_POS)
/* PLLSRC: PLL clock source */
#define RCC_PLLCFGR_PLLSRC_POS            22U
#define RCC_PLLCFGR_PLLSRC_MASK           (0x1U << RCC_PLLCFGR_PLLSRC_POS)
#define RCC_PLLCFGR_PLLSRC_HSE            (0x1U << RCC_PLLCFGR_PLLSRC_POS)
/* AHB Prescaler */
#define RCC_CFGR_HPRE_POS                 4U
#define RCC_CFGR_HPRE_MASK                (0xFU << RCC_CFGR_HPRE_POS)
#define RCC_CFGR_HPRE_DIV1                (0b0000U << RCC_CFGR_HPRE_POS)
/* APB1 Prescaler */
#define RCC_CFGR_PPRE1_POS                10U
#define RCC_CFGR_PPRE1_MASK               (0x7U << RCC_CFGR_PPRE1_POS)
#define RCC_CFGR_PPRE1_DIV2               (0x4U << RCC_CFGR_PPRE1_POS)
/* APB2 Prescaler */
#define RCC_CFGR_PPRE2_POS                13U
#define RCC_CFGR_PPRE2_MASK               (0x7U << RCC_CFGR_PPRE2_POS)
#define RCC_CFGR_PPRE2_DIV1               (0x0U << RCC_CFGR_PPRE2_POS)
/* System Clock Switch */
#define RCC_CFGR_SW_POS                   0U
#define RCC_CFGR_SW_MASK                  (0x3U << RCC_CFGR_SW_POS)
#define RCC_CFGR_SW_PLL                   (0x2U << RCC_CFGR_SW_POS)
#define RCC_CFGR_SWS_POS                  2U
#define RCC_CFGR_SWS_MASK                 (0x3U << RCC_CFGR_SWS_POS)
#define RCC_CFGR_SWS_PLL                  (0x2U << RCC_CFGR_SWS_POS)
/* RCC Clock Control Register */
#define RCC_CR_PLLON                      (0x1U << 24U)
#define RCC_CR_PLLRDY                     (0x1U << 25U)

/* AHB Prescaler: HPRE[3:0] */
#define RCC_CFGR_HPRE_POS_PCLK1             4U
#define RCC_CFGR_HPRE_MASK_PCLK1           	(0x0FU << RCC_CFGR_HPRE_POS)
#define RCC_CFGR_HPRE_DIV1_PCLK1			(0x1U << 4)

/* APB1 Prescaler: PPRE1[2:0] */
#define RCC_CFGR_PPRE1_POS_PCLK1          	10U
#define RCC_CFGR_PPRE1_MASK_PCLK1           (0x07U << RCC_CFGR_PPRE1_POS)
#define RCC_CFGR_PPRE1_DIV1_PCLK1			(1 << 10)


#define RCC_CFGR_HPRE_POS_PCLK2				4U
#define RCC_CFGR_HPRE_MASK_PCLK2			(0x0F << RCC_CFGR_HPRE_POS_PCLK2)
#define RCC_CFGR_HPRE_DIV1_PCLK2			(1U << 4U)

#define RCC_CFGR_PPRE2_POS_PCLK2          	13U
#define RCC_CFGR_PPRE2_MASK_PCLK2           (0x07U << RCC_CFGR_PPRE2_POS_PCLK2)
#define RCC_CFGR_PPRE2_DIV1_PCLK2			(1U << 13U)

/* Prescaler encoding thresholds */
#define RCC_CFGR_HPRE_DIV2_ENCODING  		8U
#define RCC_CFGR_PPRE_DIV2_ENCODING   		4U

/**
 * @brief   GPIO bit-mask and shift configuration macros.
 *
 * @details This section defines bit masks and shift values used to configure
 *          GPIO register fields.
 *
 *          The macros cover the following settings:
 *          - GPIO_MODER_BITMASK: Mask for GPIO pin mode fields.
 *          - GPIO_OSPEEDR_BITMASK: Mask for GPIO output speed fields.
 *          - GPIO_PUPDR_BITMASK: Mask for GPIO pull-up/pull-down fields.
 *          - GPIO_AFR_MASK: Mask for alternate-function fields.
 *          - GPIO_MODER_SHIFT_BITS: Shift amount for GPIO mode fields.
 *          - GPIO_OSPEEDR_SHIFT_BITS: Shift amount for GPIO speed fields.
 *          - GPIO_PUPDR_SHIFT_BITS: Shift amount for GPIO pull-up/pull-down fields.
 *          - GPIO_AFR_SIZE: Number of GPIO pins covered by one AFR register.
 *          - GPIO_AFR_MAXSIZE: Maximum alternate-function field value mask.
 *          - GPIO_AFR_SHIFT_BITS: Shift amount for alternate-function fields.
 *
 * @note    This documentation describes the supplied macro definitions.
 *          Verify their intended usage against the STM32F412xG reference manual
 *          and the GPIO driver implementation.

 *GPIO SHIFT MASK BITS*/
#define GPIO_MODER_BITMASK 		          0x3U
#define GPIO_OSPEEDR_BITMASK              0x3U
#define GPIO_PUPDR_BITMASK		          0x3U
#define GPIO_AFR_MASK     	 	          0xFU
#define GPIO_MODER_SHIFT_BITS 	          0x2U
#define GPIO_OSPEEDR_SHIFT_BITS           0x2U
#define GPIO_PUPDR_SHIFT_BITS 	          0x2U
#define GPIO_AFR_SIZE      		          0x8U
#define GPIO_AFR_MAXSIZE   		          0xfU
#define GPIO_AFR_SHIFT_BITS 	          0x4U

/**
 * @brief   FLASH Access Control Register (FLASH_ACR) configuration macros.
 *
 * @details This section defines bit positions, masks, and configuration values
 *          used to configure the FLASH_ACR register.
 *
 *          The macros cover the following settings:
 *          - Flash memory wait-state latency configuration.
 *          - Instruction prefetch enable.
 *          - Instruction cache enable.
 *          - Data cache enable.
 *
 * @note    These macros are based on the supplied definitions. Verify the
 *          register fields and configuration values against the STM32F412xG
 *          reference manual before using them in production firmware.
 *
 */
/* FLASH Access Control Register (FLASH_ACR) */
/* Latency */
#define FLASH_ACR_LATENCY_POS          0U
#define FLASH_ACR_LATENCY_MASK         (0x0FU << FLASH_ACR_LATENCY_POS)
#define FLASH_ACR_LATENCY_6WS          (6U << FLASH_ACR_LATENCY_POS)
/* Prefetch */
#define FLASH_ACR_PRFT_EN_POS           8U
#define FLASH_ACR_PRFT_EN               (1U << FLASH_ACR_PRFT_EN_POS)
/* Instruction Cache */
#define FLASH_ACR_IC_EN_POS             9U
#define FLASH_ACR_IC_EN                 (1U << FLASH_ACR_IC_EN_POS)
/* Data Cache */
#define FLASH_ACR_DC_EN_POS             10U
#define FLASH_ACR_DC_EN                 (1U << FLASH_ACR_DC_EN_POS)

/**
 * @brief   PWR control and status register configuration macros.
 *
 * @details This section defines bit positions, masks, and configuration values
 *          used to configure and monitor the Power Control (PWR) peripheral.
 *
 *          The macros cover the following settings:
 *          - Voltage scaling (VOS) field position and mask in PWR_CR.
 *          - Voltage Scale 1 configuration.
 *          - Voltage scaling ready-status flag (VOSRDY) in PWR_CSR.
 *
 * @note    These macros are based on the supplied definitions. Verify the
 *          register fields and bit positions against the STM32F412xG reference
 *          manual before using them in production firmware.
 *

 * RCC APB1 Peripheral Clock Enable Register (RCC_APB1ENR) */
#define RCC_APB1ENR_PWR_EN_POS          28U
#define RCC_APB1ENR_PWR_EN              (1U << RCC_APB1ENR_PWR_EN_POS)

/* PWR Control Register (PWR_CR) */
#define PWR_CR_VOS_POS                 	14U
#define PWR_CR_VOS_MASK                	(0x03U << PWR_CR_VOS_POS)
#define PWR_CR_VOS_SCALE1               (0x03U << PWR_CR_VOS_POS)

/* PWR Control/Status Register (PWR_CSR) */
#define PWR_CSR_VOSRDY_POS             14U
#define PWR_CSR_VOSRDY                 (1U << PWR_CSR_VOSRDY_POS)

/**
 * @brief   NVIC interrupt number definitions for STM32F412xG peripherals.
 *
 * @details This section defines interrupt request numbers (IRQn) used to
 *          identify external interrupt lines and peripheral interrupts
 *          in the Nested Vectored Interrupt Controller (NVIC).
 *
 *          The macros cover the following interrupt sources:
 *          - EXTI0 through EXTI4: Individual external interrupt lines.
 *          - EXTI9_5: Shared interrupt for external interrupt lines 5 to 9.
 *          - EXTI15_10: Shared interrupt for external interrupt lines 10 to 15.
 *          - USART1, USART2, USART3, and USART6: USART peripheral interrupts.
 *          - TIM2: Timer 2 global interrupt.
 *
 * @note    These definitions are based on the supplied macros. Verify the
 *          interrupt numbers against the STM32F412xG vector table and reference
 *          manual before using them in production firmware.
 *
 *
 *EXTI Interrupt number*/
#define EXTI0_IRQn			              6
#define EXTI1_IRQn			              7
#define EXTI2_IRQn			              8
#define EXTI3_IRQn			              9
#define EXTI4_IRQn			              10
#define EXTI9_5IRQn			              23
#define EXTI15_10IRQn    	              40

/*IRQn for USART Peripherals*/
#define USART1_IRQn			              37
#define USART2_IRQn			              38
#define USART3_IRQn			              39
#define USART6_IRQn			              71
/* TIM2 Interrupt */
#define TIM2_IRQn			              28

/**
 * @brief   USART register bit definitions and configuration macros.
 *
 * @details This section defines bit masks and configuration values used to
 *          control and monitor the USART peripheral.
 *
 *          The macros cover the following registers:
 *          - USARTx_SR  : Status flags for transmit data register empty (TXE),
 *                         transmission complete (TC), and receive data register
 *                         not empty (RXNE).
 *          - USARTx_CR1 : Oversampling mode, USART enable, transmit and receive
 *                         enable, and interrupt-enable flags.
 *          - USARTx_CR2 : Stop-bit configuration for 1, 0.5, 1.5, and 2 stop bits.
 *          - USARTx_CR3 : One-bit sampling method configuration.
 *
 * @note    These macros are based on the supplied definitions. Verify register
 *          fields and bit positions against the STM32F412xG reference manual
 *          before using them in production firmware.
 *
 *USARTx Status Register related Macros*/
#define USARTx_SR_TXE	                  (1 << 7)
#define USARTx_SR_TC	                  (1 << 6)
#define USARTx_SR_RXNE                    (1 << 5)

/*USARTx CR1 Register related Macros*/
#define USARTx_CR1_OVER8                  (1 << 15)
#define USARTx_CR1_UE	                  (1 << 13)
#define USARTx_CR1_TXEIE                  (1 << 7)
#define USARTx_CR1_TCIE                   (1 << 6)
#define USARTx_CR1RXNEIE                  (1 << 5)
#define USARTx_CR1_TE	                  (1 << 3)
#define USARTx_CR1_RE	                  (1 << 2)

/*USARTx CR2 Register related macros*/
#define USARTx_CR2_STOPBIT1               (0b00 << 12)
#define USARTx_CR2_STOPBIT0_5             (0b01 << 12)
#define USARTx_CR2_STOPBIT1_5             (0b11 << 12)
#define USARTx_CR2_STOPBIT2               (0b10 << 12)

/*USARTx CR3 Register related Macros*/
#define USARTx_CR3_ONEBIT	              (1 << 11)


/**
 * @brief   I2C register bit definitions and configuration macros.
 *
 * @details This section defines bit masks and control flags used to configure
 *          and monitor the I2C peripheral registers.
 *
 *          The macros cover the following registers:
 *          - I2C_CR1  : Peripheral enable, START, STOP, ACK, POS, and software reset.
 *          - I2C_CR2  : Peripheral clock frequency field mask.
 *          - I2C_SR1  : START, address, byte transfer, receive, transmit, and
 *                       acknowledge-failure status flags.
 *          - I2C_SR2  : Master/slave status, bus-busy status, and transfer direction.
 *          - I2C_CCR  : Clock control value mask, duty-cycle selection, and
 *                       standard/fast mode selection.
 *          - I2C_TRISE: Maximum rise-time field mask.
 *
 * @note    These macros are based on the supplied definitions. Verify register
 *          fields and bit positions against the STM32F412xG reference manual
 *          before using them in production firmware.
 *
 *CR1 macros related macros for the I2C Peripheral*/
#define I2C_CR1_PE       	              (1U << 0)
#define I2C_CR1_START    	              (1U << 8)
#define I2C_CR1_STOP     	              (1U << 9)
#define I2C_CR1_ACK      	              (1U << 10)
#define I2C_CR1_POS      	              (1U << 11)
#define I2C_CR1_SWRST    	              (1U << 15)

/*CR2 macros related macros for the I2C Peripheral*/
#define I2C_CR2_FREQ_MASK                 (0x3FU << 0)

/*SR1 macros related macros for the I2C Peripheral*/
#define I2C_SR1_SB       	              (1U << 0)
#define I2C_SR1_ADDR     	              (1U << 1)
#define I2C_SR1_BTF      	              (1U << 2)
#define I2C_SR1_RXNE     	              (1U << 6)
#define I2C_SR1_TXE      	              (1U << 7)

/*SR2 macros related macros for the I2C Peripheral*/
#define I2C_SR2_MSL     	              (1U << 0)
#define I2C_SR2_BUSY    	              (1U << 1)
#define I2C_SR2_TRA     	              (1U << 2)

/*CCR macros related macros for the I2C Peripheral*/
#define I2C_CCR_CCR_MASK                 (0x0FFFU << 0)
#define I2C_CCR_DUTY                     (1U << 14)
#define I2C_CCR_FS                       (1U << 15)

/*TRISE macros related macros for the I2C Peripheral*/
#define I2C_TRISE_MASK                   (0x3FU << 0)

/*AF macros related macros for the I2C Peripheral*/
#define I2C_SR1_AF       	             (1U << 10)

#define TIM_CR1_CEN       	             (1U << 0) /* TIM2 CR1 */
#define TIM_DIER_UIE      	             (1U << 0) /* TIM2 DIER */
#define TIM_SR_UIF        	             (1U << 0) /* TIM2 SR */
#define TIM_EGR_UG        	             (1U << 0) /* TIM2 EGR */

/**
 * @file    stm32f412xg_macros.h
 * @brief   ADC register bit definitions and configuration macros for STM32F412xG.
 *
 * @details This section defines register flags, interrupt-enable bits, resolution
 *          settings, conversion-control bits, sampling-time fields, regular
 *          conversion sequence fields, and data-register masks for the ADC
 *          peripheral.
 *
 *          The macros cover the following ADC registers:
 *          - ADC_SR     : Status register
 *          - ADC_CR1    : Control register 1
 *          - ADC_CR2    : Control register 2
 *          - ADC_SMPR1  : Sampling time register 1
 *          - ADC_SMPR2  : Sampling time register 2
 *          - ADC_SQR1   : Regular sequence register 1
 *          - ADC_SQR2   : Regular sequence register 2
 *          - ADC_SQR3   : Regular sequence register 3
 *          - ADC_DR     : Data register
 *
 * @note    These macros represent the definitions supplied for the ADC peripheral.
 *          Verify register fields, bit positions, and field encodings against the
 *          STM32F412xG reference manual before using them in production firmware.
 *
 *
 *
 *ADC_SR macros related macros for the ADC1 Peripheral*/

#define ADC_SR_AWD				          (1U << 0)
#define ADC_SR_EOC				          (1U << 1)
#define ADC_SR_JEOC         	          (1U << 2)
#define ADC_SR_JSTRT			          (1U << 3)
#define ADC_SR_STRT				          (1U << 4)
#define ADC_SR_OVR				          (1U << 5)

/*ADC_CR1 macros related macros for the ADC1 Peripheral*/
#define ADC_CR1_EOCIE			          (1U << 5)
#define ADC_CR1_SCAN			          (1U << 8)
#define ADC_CR1_OVRIE			          (1U << 26)

#define ADC_CR1_RES_MASK		          (3U << 24) //Bits 25:24 RES[1:0]: Resolution @default value SET - 11 in mask

/*ADC_CR2 macros related macros for the ADC1 Peripheral*/

#define ADC_CR2_ADON			          (1U << 0)
#define ADC_CR2_CONT			          (1U << 1)
#define ADC_CR2_ALIGN			          (1U << 11)
#define ADC_CR2_SWSTART			          (1U << 30)

/*ADC_SMPR2 macros related macros for the ADC1 Peripheral*/
#define ADC_SMPR2_SMP_00		          (7U << 0)
#define ADC_SMPR2_SMP_01		          (7U << 3)
#define ADC_SMPR2_SMP_02		          (7U << 6)
#define ADC_SMPR2_SMP_03		          (7U << 9)
#define ADC_SMPR2_SMP_04		          (7U << 12)
#define ADC_SMPR2_SMP_05		          (7U << 15)
#define ADC_SMPR2_SMP_06		          (7U << 18)
#define ADC_SMPR2_SMP_07		          (7U << 21)
#define ADC_SMPR2_SMP_08		          (7U << 24)
#define ADC_SMPR2_SMP_09		          (7U << 27)

/*ADC_SMPR1 macros related macros for the ADC1 Peripheral*/
#define ADC_SMPR1_SMP_10		           (7U << 0)
#define ADC_SMPR1_SMP_11		           (7U << 3)
#define ADC_SMPR1_SMP_12		           (7U << 6)
#define ADC_SMPR1_SMP_13		           (7U << 9)
#define ADC_SMPR1_SMP_14		           (7U << 12)
#define ADC_SMPR1_SMP_15		           (7U << 15)
#define ADC_SMPR1_SMP_16		           (7U << 18)
#define ADC_SMPR1_SMP_17		           (7U << 21)
#define ADC_SMPR1_SMP_18		           (7U << 24)

/*ADC_SQR1 macros related macros for the ADC1 Peripheral*/
#define ADC_SQR1_L				           (15U << 20) //Bits 23:20 L[3:0]: Regular channel sequence length
/*ADC_SQR3 macros related macros for the ADC1 Peripheral*/
#define ADC_SQR3_SQ_01			           (0x1FU << 0)
#define ADC_SQR3_SQ_02			           (0x1FU << 5)
#define ADC_SQR3_SQ_03			           (0x1FU << 10)
#define ADC_SQR3_SQ_04			           (0x1FU << 15)
#define ADC_SQR3_SQ_05			           (0x1FU << 20)
#define ADC_SQR3_SQ_06			           (0x1FU << 25)

/*ADC_SQR2 macros related macros for the ADC1 Peripheral*/

#define ADC_SQR2_SQ_07			           (0x1FU << 0)
#define ADC_SQR2_SQ_08			           (0x1FU << 5)
#define ADC_SQR2_SQ_09			           (0x1FU << 10)
#define ADC_SQR2_SQ_10			           (0x1FU << 15)
#define ADC_SQR2_SQ_11			           (0x1FU << 20)
#define ADC_SQR2_SQ_12			           (0x1FU << 25)

/*ADC_SQR1 macros related macros for the ADC1 Peripheral*/

#define ADC_SQR1_SQ_13			           (0x1FU << 0)
#define ADC_SQR1_SQ_14			           (0x1FU << 5)
#define ADC_SQR1_SQ_15			           (0x1FU << 10)
#define ADC_SQR1_SQ_16			           (0x1FU << 15)

/*ADC_DR macros related macros for the ADC1 Peripheral*/
#define ADC_DR_DATA				           (0xFFFF << 0)


#endif /* STM32F412XG_MACROS_H_ */
