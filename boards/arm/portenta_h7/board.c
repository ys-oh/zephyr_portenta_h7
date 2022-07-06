#include <zephyr.h>
#include <kernel.h>
#include <device.h>
#include <stm32h7xx_hal.h>

static int early_sys_init(const struct device *dev)
{
    ARG_UNUSED(dev);

    // If we are reconfiguring the clock, select CSI as system clock source to allow modification of the PLL configuration
    if (__HAL_RCC_GET_PLL_OSCSOURCE() == RCC_PLLSOURCE_HSE)
    {
        /* Reset CFGR register */
        RCC->CFGR = 0x00000000;
        /* Reset HSEON, HSECSSON, CSION, HSI48ON, CSIKERON, PLL1ON, PLL2ON and PLL3ON bits */
        RCC->CR &= 0xEAF6ED7FU;

        RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
        RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK;
        RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_CSI;
        if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
        {
            return -EINVAL;
        }
    }

    /* Enable oscillator pin */
    __HAL_RCC_GPIOH_CLK_ENABLE();
    GPIO_InitTypeDef  gpio_osc_init_structure;
    gpio_osc_init_structure.Pin = GPIO_PIN_1;
    gpio_osc_init_structure.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_osc_init_structure.Pull = GPIO_PULLUP;
    gpio_osc_init_structure.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(GPIOH, &gpio_osc_init_structure);
    HAL_GPIO_WritePin(GPIOH, GPIO_PIN_1, 1);

    return 0;
}

SYS_INIT(early_sys_init, PRE_KERNEL_1, 2);
