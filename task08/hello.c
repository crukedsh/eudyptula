#include <linux/debugfs.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/errno.h>
#include <linux/uaccess.h>
#include <linux/jiffies.h>
#include <linux/mutex.h>

#define HOBBY "ve482hobby"
#define HOBBY_LEN 11
// #define DEVICE_NAME "hobby"

// hobby

static ssize_t hobby_read(struct file* fp, char __user* user, size_t size, loff_t* offs)
{
        return simple_read_from_buffer(user,size,offs,HOBBY "!",HOBBY_LEN);
}

static ssize_t hobby_write(struct file* fp, const char __user* user, size_t size, loff_t* offs)
{
        char tmp[HOBBY_LEN];
        int res = 0;
        if (size==HOBBY_LEN) {
                res = simple_write_to_buffer(tmp, HOBBY_LEN-1, offs, user, size) + 1;
                tmp[HOBBY_LEN-1] = '\0';
        } else res = -EINVAL;
        if (*offs==HOBBY_LEN-1) {
                if (strncmp(tmp, HOBBY, HOBBY_LEN-1)) res = -EINVAL;
        }
        return res;
}

static const struct file_operations hobby_ops = {
        .owner = THIS_MODULE,
        .read = hobby_read,
        .write = hobby_write
};

// info

static DEFINE_MUTEX(info_mutex);
char msg[PAGE_SIZE];

static ssize_t info_read(struct file* fp, char __user* user, size_t size, loff_t* offs)
{
        int res = -EINVAL;
        mutex_lock(&info_mutex);
        res = simple_read_from_buffer(user,size,offs,msg,strlen(msg));
        mutex_unlock(&info_mutex);
        return res;
}

static ssize_t info_write(struct file* fp, const char __user* user, size_t size, loff_t* offs)
{
        ssize_t res;
        mutex_lock(&info_mutex);
        res = simple_write_to_buffer(msg,PAGE_SIZE,offs,user,size);
        mutex_unlock(&info_mutex);
        return res;
}

static const struct file_operations info_ops = {
        .owner = THIS_MODULE,
        .read = info_read,
        .write = info_write
};

// static struct miscdevice hello_misc = {
//         .minor = MISC_DYNAMIC_MINOR,
//         .name = DEVICE_NAME,
//         .fops = &hello_ops,
//         .mode = 0777
// };

struct dentry* ret;

static int __init hello_init(void)
{
        ret = debugfs_create_dir("ve482hobby", NULL);
        if (!debugfs_create_file("hobby", 0666, ret, NULL, &hobby_ops)){
                return -ENODEV;
        }
        if (!debugfs_create_u32("jiffies", 0444, ret, (u32*)&jiffies)){
                return -ENODEV;
        }
        if (!debugfs_create_file("info", 0644, ret, NULL, &info_ops)){
                return -ENODEV;
        }
        return 0;
}

static void __exit hello_exit(void)
{
        debugfs_remove_recursive(ret);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("ve482 hobby");
