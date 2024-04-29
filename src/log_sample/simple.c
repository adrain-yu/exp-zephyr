#include <zephyr/logging/log.h>
// 注册simple模块
LOG_MODULE_REGISTER(simple, 4);

void simple_logging(void)
{

    uint8_t data[] = { 1, 2, 3, 4, 5, 6, 7, 8,
        9, 10, 11, 12, 13, 14, 15, 16,
        17, 18, 19, 20, 21, 22, 23, 24,
        25, 26, 27, 28, 29, 30, 31, 32,
        33, 34, };

    // 以不同等级输出日志
    LOG_ERR("Error message example.");
    LOG_WRN("Warning message example.");
    LOG_INF("Info message example.");
    LOG_DBG("Debug message example.");

    //Dump二进制数据
    LOG_HEXDUMP_ERR(data, sizeof(data),"Error hexdump example:");
}
