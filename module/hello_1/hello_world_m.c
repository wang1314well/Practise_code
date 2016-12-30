#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual  BSD/GPL");

static int hello_init()
{
	printk(KERN_ALERT "hello world\n");
	return 0;
}

static void hello_exit()
{
	printk(HERN_ALERT "Goodbye!\n");
	return 0;
}

module_init(hello_init);
module_exit(hello_exit);

