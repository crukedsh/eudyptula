# Task 5

## Problem

Take the kernel module from task 1, and modify it so that when a USB keyboard is plugged in, the
module gets automatically loaded by the correct user-space hotplug tool (`udev`, now part of `systemd`).

*Hint:* refer to chapter 14 of Linux Device Drivers, 3rd edition.



## Solution

### File Description

- `hello.c`: Source of a basic module named `hello`.
- `Makefile`: A makefile for building `hello.c`.
- `README.md`: This file as readme.




### Environment

This task is conducted on Ubuntu 16.04 LTS with Linux kernel version 4.12.0.



### Procedure

1. Write `hello.c` and `Makefile`.




### Verification

1. `make` to compile the module. Note that this step generates lots of new files.
2. `modinfo hello.ko` to display the module info.
3. `insmod hello.ko` to install the module.
4. `lsmod | grep hello` to verify whether the module has been properly installed.
5. `dmesg -wH` to display messages of kernel ring buffer.
6. Plug in and out a USB keyboard and monitor the output of `dmesg`.
7. `rmmod hello` to remove the module.
8. `lsmod | grep hello` to verify whether the module has been properly removed.




## Trivia

- It is very hard to configure this module on bare machine. A bare machine is highly suggested.
