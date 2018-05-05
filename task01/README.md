# Task 1

## Problem

Write a Linux kernel module, and stand-alone `Makefile`, that when loaded prints to the kernel debug log level, "Good morning ve482!". Be sure to make the module be able to be unloaded as well.

The `Makefile` should build the kernel module against the source for the currently running kernel, or, use an environment variable to specify what kernel tree to build it against.



## Solution

### File Description

- `main.c`: Source of a basic module named `main`.
- `Makefile`: A makefile for building `main.c`.
- `README.md`: This file as readme.





### Environment

This task is conducted on Debian GNU/Linux 9 with Linux kernel version 4.12.0.



### Procedure

1. Write `main.c` and `Makefile`.




### Verification

1. `make` to compile the module. Note that this step generates lots of new files.
2. `modinfo main.ko` to display the module info.
3. `insmod main.ko` to install the module.
4. `lsmod | grep main` to verify whether the module has been properly installed.
5. `dmesg` to display messages of kernel ring buffer.
6. `rmmod` to remove the module.
7. `lsmod | grep main` to verify whether the module has been properly removed.




### Trivia

- If `MODULE_LICENSE` is not specified, the kernel will blame that the module tainted the kernel.

