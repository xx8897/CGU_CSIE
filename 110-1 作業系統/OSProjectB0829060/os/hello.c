#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
MODULE_LICENSE("Dual BSD/GPL");
static int hello_init(void){
	printk(KERN_ALERT"Hi,I am B0829060,2021\n");
	return 0;
}

static void hello_exit(void){
	printk(KERN_ALERT"Bye!\n");
}

module_init(hello_init);
module_exit(hello_exit);
