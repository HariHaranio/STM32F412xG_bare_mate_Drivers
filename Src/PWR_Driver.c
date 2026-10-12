#include "PWR_Driver.h"
#include "RCC_Driver.h"

void PWR_SetVoltageScale1(void){
    volatile uint32_t timeout = 1000000U;

    /* Enable PWR peripheral clock */
    RCC->APB1ENR |= RCC_APB1ENR_PWR_EN;

    /* Configure Voltage Scaling = Scale 1 */
    PWR->PWR_CR &= ~PWR_CR_VOS_SCALE1;
    PWR->PWR_CR |=  PWR_CR_VOS_SCALE1;

    /* Wait until Voltage Scaling is ready */
    while ((PWR->PWR_CSR & PWR_CSR_VOSRDY) == 0U){
        if (--timeout == 0U){
            break;
        }
    }
}
