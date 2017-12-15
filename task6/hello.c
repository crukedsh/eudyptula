#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/errno.h>
#include <linux/uaccess.h>
#define HOBBY "ve482hobby"
#define HOBBY_LEN 11
#define DEVICE_NAME "hobby"

static ssize_t hello_read(struct file* fp, char __user* user, size_t size, loff_t* offs){
        return simple_read_from_buffer(user,size,offs,HOBBY "!",HOBBY_LEN);
}

static ssize_t hello_write(struct file* fp, const char __user* user, size_t size, loff_t* offs){
        char tmp[HOBBY_LEN];
        int res = 0;
        if (size==HOBBY_LEN) {
                res = simple_write_to_buffer(tmp, HOBBY_LEN-1, offs, user, size) + 1;
                tmp[HOBBY_LEN-1] = '\0'; 
        } else res = -EINVAL;
        //if (*offs==HOBBY_LEN-1) {
        //        if (strncmp(tmp, HOBBY, HOBBY_LEN-1)) res = -EINVAL; 
        //}
        return res;
}

static const struct file_operations hello_ops = {
        .owner = THIS_MODULE,
        .read = hello_read,
        .write = hello_write
};

static struct miscdevice hello_misc = {
        .minor = MISC_DYNAMIC_MINOR,
        .name = DEVICE_NAME,
        .fops = &hello_ops,
        .mode = 0777
};

static int __init hello_init(void)
{
	return misc_register(&hello_misc);
}

static void __exit hello_exit(void)
{
	misc_deregister(&hello_misc);
} 

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("ve482 hobby");
