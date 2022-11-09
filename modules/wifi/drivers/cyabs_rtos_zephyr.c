#include <kernel.h>
#include <zephyr.h>

#include "cyabs_rtos.h"

/* Thread */

cy_rslt_t cy_rtos_create_thread(cy_thread_t *thread, cy_thread_entry_fn_t entry_function,
                                const char *name, void *stack, uint32_t stack_size,
                                cy_thread_priority_t priority, cy_thread_arg_t arg) 
{
    return 0;
}

cy_rslt_t cy_rtos_exit_thread(void)
{ 
    return 0;
}

cy_rslt_t cy_rtos_terminate_thread(cy_thread_t *thread)
{
    return 0;
}

cy_rslt_t cy_rtos_is_thread_running(cy_thread_t *thread, bool *state)
{
    return 0;
}

cy_rslt_t cy_rtos_join_thread(cy_thread_t *thread)
{
    return 0;
}

cy_rslt_t cy_rtos_init_semaphore(cy_semaphore_t *semaphore, uint32_t maxcount,
                                 uint32_t initcount)
{
    return 0;
}

cy_rslt_t cy_rtos_get_semaphore(cy_semaphore_t *semaphore, cy_time_t timeout_ms, bool in_isr)
{
    return 0;
}

cy_rslt_t cy_rtos_set_semaphore(cy_semaphore_t *semaphore, bool in_isr) {
    return 0;
}

cy_rslt_t cy_rtos_deinit_semaphore(cy_semaphore_t *semaphore)
{
    return 0;
}

cy_rslt_t cy_rtos_get_time(cy_time_t *tval)
{ 
    return 0;
}

cy_rslt_t cy_rtos_delay_milliseconds(cy_time_t num_ms)
{ 
    return 0;
}
