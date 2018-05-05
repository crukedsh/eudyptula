# Task 2

## Problem

The tasks for this round is:
 - Download Linus’s latest git tree from `git.kernel.org`.
 - Build it, install it, and boot it. Ensure `CONFIG_LOCALVERSION_AUTO=y` is enabled.

*Hints:* look into the `make localmodconfig` option, and base your kernel configuration on a working distro kernel configuration; Write a simple to answer all the different kernel configuration options.



## Solution

### File Description

- `README.md`: This file as readme.


### Environment

This task is conducted on Debian GNU/Linux 9 with Linux kernel version 4.9.0-4-amd64.



### Procedure

1. Download the most recent [Linux v4.12 stable release](https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux-stable.git/snapshot/linux-stable-4.12.14.tar.gz) in `/usr/src` and unzip it there. 
2. `make clean` to clean the built files.
3. `make mrproper` to clean the source tree and configurations.
4. `make localmodconfig` to load the list of running models and generate new `.config`. Press enter several times after for accepting default configurations.
5. `vim .config` and changes the commented line with `CONFIG_LOCALVERSION_AUTO` to `CONFIG_LOCALVERSION_AUTO=y ` in order to implement local version numbering.
6. `make -j4` to compile the kernel using 4 threads spontaneously.
7. `make modules_install` to install Linux modules.
8. `make install` to install Linux kernel.




### Tips

- Module configuration options in `makefile`

  There are lots of choices to deploy the configurations into `.config` file through changing the flags of `make`. Following are some common ones.

  - `make menuconfig` employs a graphic UI.
  - `make oldconfig` works on existing configurations.
  - `make localmodconfig` loads running models through `lsmod` . It seems to be the most safe one as all modules are guaranteed to function well. 
  - `make defconfig` uses default configurations.
  - `make allyesconfig` uses yes as answer to almost all the sub configurations. It is often used for module testing systems.
  - `make allnoconfig` uses no as answer to almost all the sub configurations. It is often used for embedded systems.
