#include "SysTick_Driver.h"
/*
 * Function: SysTick_Init()
 *
 * Purpose:
 * Initializes the Cortex-M4 SysTick timer.
 *
 * In this configuration:
 * - SysTick uses the processor clock
 * - SysTick generates an interrupt when the counter reaches 0
 * - The counter automatically reloads from SYSTICK_LOAD
 *
 * NOTE:
 * 16000 - 1 assumes the SysTick clock is 16 MHz
 * and we want a 1 ms period.
 */


void SysTick_Init(void){
    // Set the reload value
    SYSTICK_LOAD = 16000 - 1;

    // Clear current counter value
    SYSTICK_VAL = 0;

    // Select processor clock
    SYSTICK_CTRL |= (1 << 2);

    // Enable SysTick interrupt
    SYSTICK_CTRL |= (1 << 1);

    // Enable SysTick counter
    SYSTICK_CTRL |= (1 << 0);
}


/*
 * Millisecond counter
 *
 * Incremented every 1 ms by SysTick interrupt.
 */
volatile uint32_t msTicks = 0;


/*
 * SysTick interrupt handler
 */
void SysTick_Handler(void){
    msTicks++;
}
/*		Time          msTicks
		─────────────────────
		0 ms             0
		1 ms             1
		2 ms             2
		10 ms           10
		100 ms         100
		1000 ms       1000

 * Generate delay in milliseconds
 */
void SysTick_DelayMs(uint32_t delay){
    uint32_t start = msTicks;

    // Wait until the requested time has elapsed
    while ((msTicks - start) < delay);
}
