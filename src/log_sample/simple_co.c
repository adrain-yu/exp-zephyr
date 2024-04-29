#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(simple);

void simple_co_logging(void)
{
    LOG_ERR("Error message example co.");
    LOG_WRN("Warning message example co.");
    LOG_INF("Info message example co.");
    LOG_DBG("Debug message example co.");
}
