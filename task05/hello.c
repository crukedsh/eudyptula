#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/usb.h>
#include <linux/usb/input.h>
#include <linux/hid.h>

static struct usb_device_id hello_table[] = {
        {USB_INTERFACE_INFO(
                USB_INTERFACE_CLASS_HID,
                USB_INTERFACE_SUBCLASS_BOOT,
                USB_INTERFACE_PROTOCOL_KEYBOARD
                )},
        {}
};
MODULE_DEVICE_TABLE(usb, hello_table);

static int hello_connect(struct usb_interface *interface,
                       const struct usb_device_id* id)
{
        pr_alert("Welcome Keyboard!\n");
        return 0;
}

static void hello_disconnect(struct usb_interface* interface)
{
        pr_alert("Bye Keyboard!\n");
}

static struct usb_driver hello_driver = {
        .name = "hello_usb",
        .probe = hello_connect,
        .disconnect = hello_disconnect,
        .id_table = hello_table
};

static int __init hello_init(void)
{
        pr_debug("Good morning ve482!");
	return 0;
}

static void __exit hello_exit(void)
{
	return;
} 

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("ve482 hobby");
