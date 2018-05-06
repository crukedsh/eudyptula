#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kobject.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/errno.h>
#include <linux/uaccess.h>
#include <linux/jiffies.h>
#include <linux/mutex.h>

#define HOBBY "ve482hobby"
#define HOBBY_LEN 10

#undef VERIFY_OCTAL_PERMISSIONS
#define VERIFY_OCTAL_PERMISSIONS(perms) (perms)

// hobby

static ssize_t hobby_show(struct kobject* kobj, struct kobj_attribute* attr, char* buf)
{

        strncpy(buf, HOBBY"!", HOBBY_LEN+1);
        return HOBBY_LEN+1;
}

static ssize_t hobby_store(struct kobject* kobj, struct kobj_attribute* attr, const char* buf, size_t size)
{
        // char tmp[HOBBY_LEN+1];
        // int res = 0;
        if (size!=HOBBY_LEN+1) {
                return -EINVAL;
        }
        if (!strncmp(buf, HOBBY, HOBBY_LEN)) {
                return -EINVAL;
        }
        strncpy(HOBBY, buf, size);
        return size;
}

static struct kobj_attribute hobby_attribute = __ATTR(hobby, 0666, hobby_show, hobby_store);

// info

static DEFINE_MUTEX(info_mutex);
char msg[PAGE_SIZE];

static ssize_t info_show(struct kobject* kobj, struct kobj_attribute* attr, char* buf)
{
        mutex_lock(&info_mutex);
        strncpy(buf, msg, strlen(msg));
        mutex_unlock(&info_mutex);
        return strlen(msg);
}

static ssize_t info_store(struct kobject* kobj, struct kobj_attribute* attr, const char* buf, size_t size)
{
        if (size>PAGE_SIZE) return -EINVAL;
        mutex_lock(&info_mutex);
        strncpy(msg, buf, size);
        mutex_unlock(&info_mutex);
        return size;
}


static struct kobj_attribute info_attribute = __ATTR(info, 0644, info_show, info_store);

// jiffies

static ssize_t jiffies_show(struct kobject* kobj, struct kobj_attribute* attr, char* buf)
{
        return sprintf(buf, "%lu\n", jiffies);
}

static struct kobj_attribute jiffies_attribute = __ATTR(jiffies, 0444, jiffies_show, NULL);

// module

static struct attribute* attrs[] = {
        &hobby_attribute.attr,
        &info_attribute.attr,
        &jiffies_attribute.attr,
        NULL,
};

static struct attribute_group hello_group = {
        .attrs = attrs,
};

static struct kobject* hello_kobj;

static int __init hello_init(void)
{
        int res;
        hello_kobj = kobject_create_and_add("ve482hobby", kernel_kobj);
        if (!hello_kobj) return -ENOMEM;
        res = sysfs_create_group(hello_kobj, &hello_group);
        if (res) kobject_put(hello_kobj);
        return res;
}

static void __exit hello_exit(void)
{
        kobject_put(hello_kobj);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("ve482 hobby");
