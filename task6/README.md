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



## Solution

### File Description

- `main.c`: Source of a basic module named `main`.
- `Makefile`: A makefile for building `main.c`.
- `README.md`: This file as readme.



### Environment

This task is complete on Ubuntu 16.04 LTS with Linux kernel version 4.12.0.



### Procedure

1. Write `main.c` and `Makefile`.



### Verification

1. `make` to compile the module. Note that this step generates lots of new files.
2. `modinfo main.ko` to display the module info.
3. `insmod main.ko` to install the module.
4. `lsmod | grep main` to verify whether the module has been properly installed.
5. `echo ve482hobby > /dev/hobby` to find normal output.
6. `echo ve477hobby > /dev/hobby` to find error information.
7. `cat /dev/hobby` to read greetings.
8. `rmmod` to remove the module.
9. `lsmod | grep main` to verify whether the module has been properly removed.