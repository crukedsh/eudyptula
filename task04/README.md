# Task 4

## Problem

Part of the job of being a kernel developer is recognizing the proper *Linux kernel coding style*. The full description of this coding style can be found in the kernel itself (`Documentation/CodingStyle`). There is also a tool (`checkpatch.pl` in the `scripts` directory) available from the kernel source tree.

The task for this round consists in refactoring the module from the first task such that it meets the requirements of the Linux kernel coding style.

*Note:* it is important that everyone follow the same standard so that the patterns become consistent. In other words, you want to make it really easy for other people to find the bugs in your code, and not be confused and distracted by other unimportant things (e.g. prefer spaces instead of tabs for indentation).



## Solution

### File Description

- `hello.c`: Source of a basic module named `hello`.
- `Makefile`: A makefile for building `hello.c`.
- `README.md`: This file as readme.





### Environment

This task is conducted on Debian GNU/Linux 9 with Linux kernel version 4.12.0.



### Procedure

1. Refer to `Documentation/CodingStyle` for coding style.
2. Modify `hello.c` and `Makefile` to satisfy the requirements.




### Verification

1. `make` to compile the module. Note that this step generates lots of new files.
2. `modinfo hello.ko` to display the module info.
3. `insmod hello.ko` to install the module.
4. `lsmod | grep hello` to verify whether the module has been properly installed.
5. `dmesg` to display messages of kernel ring buffer.
6. `rmmod` to remove the module.
7. `lsmod | grep hello` to verify whether the module has been properly removed.




## Trivia

 - Key points in `CodingStyle`
   - Indentation
   - Naming of functions and variables
   - Functions
   - Loops
   - Comments

