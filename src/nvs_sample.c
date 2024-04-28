#include <zephyr.h>
#include <shell/shell.h>

#include <drivers/flash.h>
#include <storage/flash_map.h>
#include <fs/nvs.h>

static struct nvs_fs fs;

#define STORAGE_NODE_LABEL storage


static int nvs_cmd_show(const struct shell *shell, size_t argc, char **argv)
{

}

static int nvs_cmd_init(const struct shell *shell, size_t argc, char **argv)
{
    int rc = 0;
    struct flash_pages_info info;
	const struct device *flash_dev;

	flash_dev = FLASH_AREA_DEVICE(STORAGE_NODE_LABEL);
	if (!device_is_ready(flash_dev)) {
		printk("Flash device %s is not ready\n", flash_dev->name);
		return;
	}
	fs.offset = FLASH_AREA_OFFSET(storage);
	rc = flash_get_page_info_by_offs(flash_dev, fs.offset, &info);
	if (rc) {
		printk("Unable to get page info\n");
		return;
	}
	fs.sector_size = info.size*2;
	fs.sector_count = 3U;

	rc = nvs_init(&fs, flash_dev->name);
	if (rc) {
		printk("Flash Init failed\n");
		return;
	}
}

static int nvs_cmd_erase(const struct shell *shell, size_t argc, char **argv)
{
    int rc = 0;
    struct flash_pages_info info;
	const struct device *flash_dev;
    struct flase_area *storage_area = NULL;

	flash_dev = FLASH_AREA_DEVICE(STORAGE_NODE_LABEL);
	if (!device_is_ready(flash_dev)) {
		printk("Flash device %s is not ready\n", flash_dev->name);
		return;
	}
	fs.offset = FLASH_AREA_OFFSET(storage);
	rc = flash_get_page_info_by_offs(flash_dev, fs.offset, &info);
	if (rc) {
		printk("Unable to get page info\n");
		return;
	}
	fs.sector_size = info.size;
	fs.sector_count = 3U;

    rc = flash_area_open(FLASH_AREA_ID(STORAGE_NODE_LABEL), &storage_area);
    if (rc) {
		printk("flash_area_open fail\n");
		return;
	}

	rc = flash_area_erase(storage_area, 0, fs.sector_count*fs.sector_size);
    if (rc) {
		printk("erase page fail\n");
		return;
	}
}

SHELL_STATIC_SUBCMD_SET_CREATE(sub_nvs,
			       SHELL_CMD(show, NULL, "show nvs info", nvs_cmd_show),
                   SHELL_CMD(init, NULL, "nvs init", nvs_cmd_init),
                   SHELL_CMD(erase, NULL, "nvs init", nvs_cmd_erase),
			       SHELL_SUBCMD_SET_END
			       );

SHELL_CMD_REGISTER(nvs, &sub_nvs, "nvs test commands", NULL);