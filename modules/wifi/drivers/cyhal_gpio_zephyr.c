#include <kernel.h>
#include <zephyr.h>

#include "cyhal_gpio.h"

/* GPIO */

cy_rslt_t cyhal_gpio_init(cyhal_gpio_t pin, cyhal_gpio_direction_t direction, cyhal_gpio_drive_mode_t drvMode,
                          bool initVal)
{
    return 0;
}

void cyhal_gpio_free(cyhal_gpio_t pin)
{
}

cy_rslt_t cyhal_gpio_direction(cyhal_gpio_t pin, cyhal_gpio_direction_t direction)
{
    return 0;
}

cy_rslt_t cyhal_gpio_drivemode(cyhal_gpio_t pin, cyhal_gpio_drive_mode_t drvMode)
{
    return 0;
}

void cyhal_gpio_write(cyhal_gpio_t pin, bool value)
{
}

bool cyhal_gpio_read(cyhal_gpio_t pin)
{
    return 0;
}

void cyhal_gpio_toggle(cyhal_gpio_t pin)
{
}

void cyhal_gpio_register_irq(cyhal_gpio_t pin, uint8_t intrPriority, cyhal_gpio_irq_handler_t handler,
                             void *handler_arg)
{
}

void cyhal_gpio_irq_enable(cyhal_gpio_t pin, cyhal_gpio_irq_event_t event, bool enable)
{
}