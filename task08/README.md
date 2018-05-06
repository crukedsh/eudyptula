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
- The file `info` needs to be writable only by root, but readable by anyone. When writing to it, the value must be stored, up to one page of data. On a read the file content should be displayed.
- When the module is unloaded, all of the `debugfs` files must be cleaned up, and any memory allocated freed.

*Hint:* properly handle the fact that someone could be reading from the file comment while someone else
is writing to it.

*Note:* never use `/proc/`, that is reserved for processes, when printing out debugging information, rather
use `debugfs`.



## Solution

### File Description

- `hello.c`: Source of a basic module named `hello`.
- `Makefile`: A makefile for building `hello.c`.
- `README.md`: This file as readme.

### Environment

This task is conducted on Ubuntu 16.04 LTS with Linux kernel version 4.13.0.



### Procedure

1. Write `hello.c` and `Makefile`.

### Verification

1. `mount | grep debugfs` to verify whether `debugfs` is mounted. If yes, skip to step 3.
2. `mount -t debugfs none /sys/kernel/debug` to mount `debugfs`.
3. `make` to compile the module. Note that this step generates lots of new files.
4. `modinfo hello.ko` to display the module info.
5. `insmod hello.ko` to install the module.
6. `lsmod | grep hello` to verify whether the module has been properly installed.
7. `echo ve482hobby > /sys/kernel/debug/ve482hobby/hobby` to find normal output, which should be nothing.
8. `echo ve477hobby > /sys/kernel/debug/ve482hobby/hobby` to find error information.
9. `cat /sys/kernel/debug/ve482hobby/hobby` to read greetings.
10. `cat /sys/kernel/debug/ve482hobby/jiffies` to see current jiffies, the number of ticks occurred since system start-up.
11. `echo hahahaha > /sys/kernel/debug/ve482hobby/info` to store information.
12. `cat /sys/kernel/debug/ve482hobby/info` to read the information from the last step.
13. `rmmod hello` to remove the module.
14. `lsmod | grep hello` to verify whether the module has been properly removed.

### Trivia

- From this task on, this project is served as a final project of course Software System in Olin College of Engineering. It is instructed by Dr. Allen Downey.
- Documentation about `debugfs` can be found under `Documentation/filesystems/debugfs.txt`.
- Mutexes are important -- and much easier to handle than semaphores.
