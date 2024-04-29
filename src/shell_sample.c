#include <stdlib.h>
#include <zephyr/kernel.h>
#include <version.h>
#include <zephyr/shell/shell.h>

static int cmd_info_board(const struct shell *sh, size_t argc, char **argv)
{
	ARG_UNUSED(argc);
	ARG_UNUSED(argv);

	shell_print(sh, CONFIG_BOARD);
	shell_info(sh, CONFIG_BOARD);
	shell_warn(sh, CONFIG_BOARD);
	shell_error(sh, CONFIG_BOARD);


	return 0;
}

static int cmd_info_version(const struct shell *sh, size_t argc, char **argv)
{
	ARG_UNUSED(argc);
	ARG_UNUSED(argv);

	shell_print(sh, "Zephyr version %s", KERNEL_VERSION_STRING);

	return 0;
}


static int cmd_shell_help(const struct shell *sh, size_t argc, char **argv)
{
	shell_print(sh, "show help: %d", argc);
    if(argc == 1){
        shell_help(sh);
        return SHELL_CMD_HELP_PRINTED;
    }

	for(size_t i=0; i< argc; i++){
		shell_print(sh, "check arg %d: %s", i, argv[i]);
	}

	return 0;
}

/* SHELL_CMD 注册两个子命令， board和version，执行时会调用cmd_info_board和cmd_info_version函数
   SHELL_STATIC_SUBCMD_SET_CREATE 将子命令组装成子命令集subinfo
   SHELL_SUBCMD_SET_END表示子命令集的结束
 */
SHELL_STATIC_SUBCMD_SET_CREATE(subinfo,
    SHELL_CMD(board, NULL, "Show board command.", cmd_info_board),
    SHELL_CMD(version, NULL, "Show info command.", cmd_info_version),
    SHELL_SUBCMD_SET_END /* Array terminated. */
);

/* 注册一个根命令shell_sample，执行根命令shell_sample时会调用cmd_shell_help
    shell_sample的子命令集为
 */
SHELL_CMD_REGISTER(shell_sample, &subinfo, "Sample commands", cmd_shell_help);

