#include <zephyr.h>
#include <ztest.h>

#include <zephyr.h>
#include <kernel.h>
#include <device.h>
#include <drivers/gpio.h>
#include <drivers/led.h>


#if DT_NODE_HAS_STATUS(DT_NODELABEL(sdram1), okay)

#define BUF_SIZE 64U

/** Buffer on SDRAM1. */
__stm32_sdram1_section uint32_t sdram1[BUF_SIZE];

static void sdram_rw_test(void);
{
  uint32_t* mem = sdram1;

	/* fill memory with number range (0, BUF_SIZE - 1) */
	for (size_t i = 0U; i < BUF_SIZE; i++) {
		mem[i] = i;
	}

	/* check that memory contains written range */
	for (size_t i = 0U; i < BUF_SIZE; i++)
  {
		zassert_equal(mem[i], i, "Unexpected content");
	}
}

#endif

void test_main(void)
{
	ztest_test_suite(portenta_test_suite,
#if DT_NODE_HAS_STATUS(DT_NODELABEL(sdram1), okay)
		ztest_unit_test(sdram_rw_test),
#endif
	);

	ztest_run_test_suite(portenta_test_suite);
}
