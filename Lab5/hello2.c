// SPDX-License-Identifier: GPL-2.0
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>
#include <linux/errno.h>

#include "hello1.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Lozinska Mariia");
MODULE_DESCRIPTION("Hello2 module using hello1");

static unsigned int count = 1;

module_param(count, uint, 0444);
MODULE_PARM_DESC(count, "Number of Hello World messages");

static int __init hello2_init(void)
{
	unsigned int i;
	int ret;

	if (count > 10) {
		pr_err("Invalid count: %u\n", count);
		return -EINVAL;
	}

	if (count == 0 || (count >= 5 && count <= 10))
		pr_warn("Warning: count = %u\n", count);

	for (i = 0; i < count; i++) {
		ret = print_hello();
		if (ret)
			return ret;
	}

	return 0;
}

static void __exit hello2_exit(void)
{
	pr_info("Hello2 module unloaded\n");
}

module_init(hello2_init);
module_exit(hello2_exit);
