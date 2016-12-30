#include <linux/cdev.h>
#include <asm/io.h>
//#include <asm/system.h>
#include <asm/switch_to.h>
#include <asm/uaccess.h>

#include "memdev.h"

static mem_major = MEMDEV_MAJOR;
module_param(mem_major,int,S_IRUGO);
struct	mem_dev	*mem_devp;
struct	cdev	cdev;

static loff_t mem_llseek(struct file *filp, loff_t offset,int whence)
{
	loff_t newpos;

	switch(whence)
	{
		case 0:
			newpos = offset;
			break;
		case 1:
			newpos = file->f_ops + offset;
			break;
		case 2:
			newpos = MEMDEV_SIZE - 1 + offset;
			break;

		default:
			return -EINVAL;
	}
	if((newpos < 0) || (newpos->MEMDEV_SIZE))
		return -EINVAL;
	filp->f_pos = newpos;
	return newpos;

}

int mem_open(struct inode *inode,struct file *filp)
{
//	struct mem_dev *dev;
	return 0	;
}

int mem_release(struct inode *inode,struct file *filp)
{
	return 0;
}

static ssize_t mem_read(struct file *filp,char __user *buf,size_t size,loff_t *ppos)
{
	unsigned long p = **ppos;
}

static ssize_t mem_write(struct file *filp,const char __user *buf,size_t size,loff_t *ppos)
{
	unsigned long p = **ppos;
}

static const struct file_operations mem_fops = 
{
	.owner = THIS_MODULE,
	.llseek = mem_llseek,
	.read = mem_read,
	.write = mem_write,
	.open = mem_open,
	.release = mem_release
};


static int memdev_init(void)
{
	int result;
	int i;

	dev_t	devno = MKDEV(mem_major, 0);

	if(mem_major)
		result = register_chrdev_region(devno, 2, "memdev");
	else
	{
		result = alloc_chrdev_region(&devno, 0, 2, "memdev");
		mem_major = MAJOR(devno);
	}

	if(result < 0)
		return result;
	
	cdev_init(&cdev ,&mem_fops );
	cdev.owner = THIS_MODULE;
	cdev.ops = &mem_fops;

	cdev_add(&cdev, MKDEV(mem_major, 0), MEMDEV_NR_DEVS);

	mem_devp = kmalloc(MEMDEV_NR_DEVS * sizeof(struct mem_dev), GFP_KERNEL);
	if(!mem_devp)
	{
		result = -ENOMEM;
		goto fail_malloc;
	}
	memset(mem_devp,0,sizeof(struct mem_dev));

	for(i = 0; i<MEMDEV_NR_DEVS; i++)
	{
		mem_devp[i].size = MEMDEV_SIZE;
		mem.devp[i].data = kmalloc(MEMDEV_SIZE,GFP_KERNEL);
		memset(mem_devp[i].data, 0 ,MEMDEV_SIZE);
	}

	return 0;

	fail_malloc:
		unregister_chrdev_region(devno, 1);

	return result;

}

static void memdev_exit(void)
{
	cdev_del(&cdev);
	kfree(mem_devp);
	unregister_chrdev_region(MKDEV(mem_major, 0) , 2);
}







MODULE_AUTHOR("David");
MODULE_LICENSE("GPL");

module_init(memdev_init);
module_exit(memdev_exit);

