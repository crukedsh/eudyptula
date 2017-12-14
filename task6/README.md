# Task 6

## Problem

The task this time is as follows:

- Take the kernel module you wrote for task 1, and modify it to be a misc char device driver.
- The misc device should be created with a dynamic minor number.
- The misc device should implement the read and write functions.
- The misc device node should show up in `/dev/hobby`.
- When the character device node is read from, it returns “ve482hobby!”.
- When the character device node is written to, the data sent to the kernel needs to be checked. If it matches the string “ve482hobby”, then return a correct write return value. Otherwise return the “invalid value” error value.
- The misc device should be registered when the module is loaded, and unregistered when it is
  unloaded.

*Note:* the misc interface is a very simple way to be able to create a character device, without having to
worry about all of the `sysfs` and character device registration mess.

*Hint:* no need to reserve a real minor number for the test module.