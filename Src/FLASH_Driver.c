#include "FLASH_Driver.h"

/* Configure Flash interface for 100 MHz operation */
void FLASH_ConfigFor100MHz(void)
{
    /* Configure Flash latency = 6 wait states */
    FLASH->FLASH_ACR &= ~(FLASH_ACR_LATENCY_MASK);
    FLASH->FLASH_ACR |=  FLASH_ACR_LATENCY_6WS;

    /* Enable prefetch */
    FLASH->FLASH_ACR |= FLASH_ACR_PRFT_EN;

    /* Enable instruction cache */
    FLASH->FLASH_ACR |= FLASH_ACR_IC_EN;

    /* Enable data cache */
    FLASH->FLASH_ACR |= FLASH_ACR_DC_EN;
}
