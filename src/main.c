/*
 * Copyright (c) 2022 Frank.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/shell/shell.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/util.h>

#define STACKSIZE 1024
//注册一个名为main的log frontend, build-in level为LOG_LEVEL_DBG
LOG_MODULE_REGISTER(main, LOG_LEVEL_DBG);

static K_THREAD_STACK_DEFINE(stack, STACKSIZE);
static struct k_thread main_thread;

static void log_thread_fun(void *p1, void *p2, void *p3)
{
    int i = 0;
    while(1){
        LOG_ERR("main err %d", i++);    //ERR Level log
        LOG_WRN("main wrn");            //WRN Level log
        LOG_INF("main info");           //INFO Level log
        LOG_DBG("main dbg");            //DBG Level log
        //k_sleep(1000);
	k_sleep(K_MSEC(1000000000));
    }
}
extern void simple_logging(void);
extern void simple_co_logging(void);
void main(void)
{
    simple_logging();
    k_thread_create(&main_thread, stack, STACKSIZE, log_thread_fun, NULL, NULL,
			NULL, K_PRIO_COOP(7), 0, K_NO_WAIT);

    simple_co_logging();
}
