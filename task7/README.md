# Task 7

## Problem

The tasks this round consist in downloading today’s “linux-next kernel”, build it, and boot it.

*Hint:* refer to the Linux kernel is development process in `Documentation/development-process/` in
the kernel source itself.



## Solution

### File Description

- `README.md`: This file as readme.

  ​

### Environment

This task is complete on Ubuntu 16.04 LTS with Linux kernel version 4.12.0.



### Procedure

1. Download the most recent [Linux release](https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/snapshot/linux-50c4c4e268a2d7a3e58ebb698ac74da0de40ae36.tar.gz) in `/usr/src` and unzip it here. 
2. `make clean` to clean the built files.
3. `make mrproper` to clean the source tree and configurations.
4. `make localmodconfig` to load the list of running models and generate new `.config`. Press enter several times after for accepting default configurations.
5. `vim .config` and changes the commented line with `CONFIG LOCALVERSION AUTO` to `CONFIG LOCALVERSION AUTO=y ` in order to implement local version numbering.
6. `make -j4` to compile the kernel using 4 threads spontaneously.
7. `make modules_install` to install Linux modules.
8. `make install` to install Linux kernel.




### Trivia

- I installed Linux 4.15-rc3 and then removed it because I am quite afraid of `rc`. 