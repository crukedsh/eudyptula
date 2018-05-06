# Task 9

## Problem

Another "interface" for interaction between the kernel and the user is `sysfs`. For this task adapt the
code from task 8 to `sysfs`. In particular, put the `ve482hobby` directory under `/sys/kernel/`.

*Hint:* this is not a simple task; refer to `Documentation/kobject.txt` to understand how to use `kobjects`
and `sysfs`.



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

1. `make` to compile the module. Note that this step generates lots of new files.
2. `modinfo hello.ko` to display the module info.
3. `insmod hello.ko` to install the module.
4. `lsmod | grep hello` to verify whether the module has been properly installed.
5. `echo ve482hobby > /sys/kernel/ve482hobby/hobby` to find normal output, which should be nothing.
6. `echo ve477hobby > /sys/kernel/ve482hobby/hobby` to find error information.
7. `cat /sys/kernel/ve482hobby/hobby` to read greetings.
8. `cat /sys/kernel/ve482hobby/jiffies` to see current jiffies, the number of ticks occurred since system start-up.
9. `echo hahahaha > /sys/kernel/ve482hobby/info` to store information.
10. `cat /sys/kernel/ve482hobby/info` to read the information from the last step.
11. `rmmod hello` to remove the module.
12. `lsmod | grep hello` to verify whether the module has been properly removed.

## Trivia

- `sysfs` does not allow files to have permission of `0666`. It calls `VERIFY_OCTAL_PERMISSIONS` to check this. To bypass the checking process, the macro should be redefined.

  ```c
  #undef VERIFY_OCTAL_PERMISSIONS
  #define VERIFY_OCTAL_PERMISSIONS(perms) (perms)
  ```

  ​