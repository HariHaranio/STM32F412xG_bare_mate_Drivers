# STM32F412xG Bare-Metal Drivers

Bare-metal driver development for the **STM32F412xG** using **Embedded C** and direct register-level programming.

## Objective

* Understand STM32F412xG peripherals at register level
* Develop reusable peripheral drivers
* Practice firmware development without HAL or CubeMX
* Build and test real hardware applications

> [!NOTE]
> Learning and developing STM32 bare-metal firmware through register-level programming.

## Drivers

* RCC [.h](https://github.com/HariHaranio/STM32F412xG_bare_mate_Drivers/blob/main/Device_Driver/Inc/RCC_Driver.h)  [.c](https://github.com/HariHaranio/STM32F412xG_bare_mate_Drivers/blob/main/Device_Driver/Src/RCC_Driver.c)
* GPIO [.h](https://github.com/HariHaranio/STM32F412xG_bare_mate_Drivers/blob/main/Device_Driver/Inc/GPIO_Driver.h)  [.c](https://github.com/HariHaranio/STM32F412xG_bare_mate_Drivers/blob/main/Device_Driver/Src/GPIO_Driver.c)
* SysTick  [.h](https://github.com/HariHaranio/STM32F412xG_bare_mate_Drivers/blob/main/Device_Driver/Inc/SysTick_Driver.h)  [.c](https://github.com/HariHaranio/STM32F412xG_bare_mate_Drivers/blob/main/Device_Driver/Src/SysTick_Driver.c)
* EXTI  [.h](https://github.com/HariHaranio/STM32F412xG_bare_mate_Drivers/blob/main/Device_Driver/Inc/EXTI_Driver.h)  [.c](https://github.com/HariHaranio/STM32F412xG_bare_mate_Drivers/blob/main/Device_Driver/Src/EXTI_Driver.c)
* NVIC  [.h](https://github.com/HariHaranio/STM32F412xG_bare_mate_Drivers/blob/main/Device_Driver/Inc/NVIC_Driver.h)  [.c](https://github.com/HariHaranio/STM32F412xG_bare_mate_Drivers/blob/main/Device_Driver/Src/NVIC_Driver.c)
* UART  [.h](https://github.com/HariHaranio/STM32F412xG_bare_mate_Drivers/blob/main/Device_Driver/Inc/USART_Driver.h)  [.c](https://github.com/HariHaranio/STM32F412xG_bare_mate_Drivers/blob/main/Device_Driver/Src/USART_Driver.c)
* SYSCONFIG  [.h](https://github.com/HariHaranio/STM32F412xG_bare_mate_Drivers/blob/main/Device_Driver/Inc/SYSCONFIG_Driver.h)  [.c](https://github.com/HariHaranio/STM32F412xG_bare_mate_Drivers/blob/main/Device_Driver/Src/SYSCONFIG_Driver.c)
* SPI 
* I2C 
* ADC
* Timers
* PWM
* Watchdog

## Development Approach

**Datasheet → Reference Manual → Registers → Driver → Hardware Testing**


## Tools

🔧 STM32F412xG, 
💻 Embedded C, 
🛠️ STM32CubeIDE,
📝 VS Code,
🌐 Git & GitHub.

## Resources
> STM32F412xG 
* [STM32F412 Product Page – STMicroelectronics](https://www.st.com/en/microcontrollers-microprocessors/stm32f412.html)
* [STM32F412xG -> Datasheet](https://www.st.com/resource/en/datasheet/stm32f412zg.pdf)
* [STM32F412xG -> RM0402 Reference Manual](https://www.st.com/resource/en/reference_manual/rm0402-stm32f412zg-stm32f412vg-stm32f412tg-stm32f412cg-stm32f412rg-stm32f412ng-stm32f412wg-stm32f412xg-series.pdf)

> NUCLEO-F412ZG
* [NUCLEO-F412ZG Product Page – STMicroelectronics](https://www.st.com/en/evaluation-tools/nucleo-f412zg.html)
* [NUCLEO-F412ZG -> User Manual](https://www.st.com/resource/en/user_manual/um1974-stm32-nucleo144-boards-mb1137-stmicroelectronics.pdf)
* [NUCLEO-F412ZG -> Pin Documentation](https://nrfconnectdocs.nordicsemi.com/ncs/2.2.0/zephyr/boards/arm/nucleo_f412zg/doc/index.html)
  
> [!NOTE]
> This the board I tested the code.
<img width="426" height="830" alt="image" src="https://github.com/user-attachments/assets/c85fb3ae-b768-4f4f-8d76-05ed180bdf7f" />

