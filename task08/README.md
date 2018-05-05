# Task 8

## Problem

In this task we focus on the `debugfs` user/kernel interface. It is rumored that the creator of `debugfs`
said that there is only one rule for debugfs use: "There are no rules when using debugfs." So let's take
them up on that offer and see how to use it.

First ensure `debugfs` is (i) enabled in the currently running kernel (`CONFIG_DEBUG_FS` option) and
(ii) mounted (usually mounted on `/sys/kernel/debug/`).

The task is described as follows:

- Take the kernel module from task 1, and modify it to create a `debugfs` subdirectory called `ve482hobby`. In that directory, create three virtual files called `hobby`, `jiffies`, and `info`.


- The file `hobby` should operate just like it did in task 6; reuse the same logic, and ensure the file is readable and writable by any user.
- The file `jiffies` is to be read by any user, and when read, should return the current value of the jiffies kernel timer.
- The file `info` needs to be writable only by root, but readable by anyone. When writing to it, the

value must be stored, up to one page of data. On a read the file content should be displayed.
 When the module is unloaded, all of the debugfs files must be cleaned up, and any memory
allocated freed;
Hint: properly handle the fact that someone could be reading from the file comment while someone else
is writing to it.
Note: never use /proc/, that is reserved for processes, when printing out debugging information, rather
use debugfs.



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