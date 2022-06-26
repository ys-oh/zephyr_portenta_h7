#include <logging/log.h>
LOG_MODULE_REGISTER(main);

#include <zephyr.h>
#include <kernel.h>
#include <device.h>
#include <drivers/gpio.h>
#include <drivers/led.h>

void main(void)
{
    const struct device* dev = DEVICE_DT_GET(DT_NODELABEL(gpioled)); 
    if (!device_is_ready(dev))
    {
        LOG_ERR("gpioled is not ready.");
        return;
    }

    while (1)
    {
#ifdef CONFIG_CPU_CORTEX_M7
        LOG_INF("led on\n");
        led_on(dev, 0);
        led_on(dev, 1);
        k_sleep(K_MSEC(500));

        LOG_INF("led off\n");
        led_off(dev, 0);
        led_off(dev, 1);
        k_sleep(K_MSEC(500));
#else
        led_on(dev, 2);
        k_sleep(K_MSEC(100));
        led_off(dev, 2);
        k_sleep(K_MSEC(100));
#endif
    }
}
