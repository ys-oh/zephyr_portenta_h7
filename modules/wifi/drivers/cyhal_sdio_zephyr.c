#include <kernel.h>
#include <zephyr.h>

#include "cyhal_sdio.h"

/* SDIO */

cy_rslt_t cyhal_sdio_init(cyhal_sdio_t *obj, cyhal_gpio_t cmd, cyhal_gpio_t clk, cyhal_gpio_t data0, cyhal_gpio_t data1,
                          cyhal_gpio_t data2, cyhal_gpio_t data3)
{
    return 0;
}

void cyhal_sdio_free(cyhal_sdio_t *obj)
{
}

cy_rslt_t cyhal_sdio_configure(cyhal_sdio_t *obj, const cyhal_sdio_cfg_t *config)
{
    return 0;
}


cy_rslt_t cyhal_sdio_send_cmd(const cyhal_sdio_t *obj, cyhal_transfer_t direction, cyhal_sdio_command_t command,
                              uint32_t argument, uint32_t *response)
{
    return 0;
}

cy_rslt_t cyhal_sdio_bulk_transfer(cyhal_sdio_t *obj, cyhal_transfer_t direction, uint32_t argument,
                                   const uint32_t *data, uint16_t length, uint32_t *response)
{
    return 0;
}

cy_rslt_t cyhal_sdio_transfer_async(cyhal_sdio_t *obj, cyhal_transfer_t direction, uint32_t argument,
                                    const uint32_t *data, uint16_t length)
{
    return 0;
}

bool cyhal_sdio_is_busy(const cyhal_sdio_t *obj)
{
    return 0;
}

cy_rslt_t cyhal_sdio_abort_async(const cyhal_sdio_t *obj)
{
    return 0;
}

void cyhal_sdio_register_irq(cyhal_sdio_t *obj, cyhal_sdio_irq_handler_t handler, void *handler_arg)
{
}

void cyhal_sdio_irq_enable(cyhal_sdio_t *obj, cyhal_sdio_irq_event_t event, bool enable)
{
}
