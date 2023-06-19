#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

MODULE_LICENSE("Dual BSD/GPL");

static int Module_B0329044_init(void)
{
	printk(KERN_ALERT"Hi, I am B0329044!\n");
	return 0;
}

static void Module_B0329044_exit(void)
{
	printk(KERN_ALERT"Bye!\n");
}

module_init(Module_B0329044_init);
module_exit(Module_B0329044_exit);
