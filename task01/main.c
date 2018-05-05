#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init ve482hobby_init(void){
	printk(KERN_DEBUG "Good morning ve482!");
	return 0;
}

static void __exit ve482hobby_exit(void){
	return;
} 

module_init(ve482hobby_init);
module_exit(ve482hobby_exit);

MODULE_LICENSE("GPL");
