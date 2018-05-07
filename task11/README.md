# Task 11

This task is NOT completed.

## Problem

After working with `kobject` and `sysfs` in task 9, we move one level up the tree and start to mess with devices and not raw `kobjects`.

For this task:

- Write a patch against any driver that you are currently using on your machine.
- In that driver, add a `sysfs` file to show up in the `/sys/devices/` tree for the device that is called "hobby". As you might expect, this file follows the same rules as task 9 as for what you can read and write to it.
- The file is to show up only for devices that are controlled by a single driver, not for all devices of a single type (like all USB devices).

*Hint:* First you have to figure out which drivers you are using, and where the source code in the kernel tree is for that driver.



## Solution

### File Description

- `0001-hobby-sysfs-FTDI-Xdriver-serial.patch`: A patch containing task-oriented changes.
- `README.md`: This file as readme.

### Environment

This task is conducted on Ubuntu 16.04 LTS with Linux kernel version 4.13.0.



### Procedure

1. Find source of one of the most common USB drivers in  `drivers/usb/serial/ftdi_sio.c`.

2. Backup the original source, and create a working archive with `cp` named as `linux-4.17-rc3-modf`.

3. `vim linux-4.17-rc3-modf/drivers/usb/serial/ftdi_sio.c` and modify the codings.

4. `diff -uprN -X linux-4.17-rc3-modf/Documentation/dontdiff linux-4.17-rc3 linux-4.17-rc3-modf > 0001-hobby-sysfs-FTDI-Xdriver-serial.patch` to generate a patch.

5. Add the signature in the first line.

   ```
   Signed-off-by: Zhengyang Feng <crukedshfeng@gmail.com>
   ```

6. `perl linux-4.17-rc3/scripts/checkpatch.pl 0001-hobby-sysfs-FTDI-Xdriver-serial.patch` to check the correctness.

### Verification

1. Buy a USB device with FTDI X series as the main chip.
2. Under source directory, `patch -p1 < ../0001-hobby-sysfs-FTDI-Xdriver-serial.patch`c. Notice the output information as `patching file drivers/usb/serial/ftdi_sio.c`.
3. Plug the device in. Find the device by `find /sys/devices/ -name ttyUSB*`. `cd ` to the directory.
4. `echo ve482hobby > hobby` to find normal output, which should be nothing.
5. `echo ve477hobby > hobby` to find error information.
6. `cat hobby` to read greetings.

## Trivia

- I don't have FTDI devices around, even an Arduino board. So actually I didn't test the patch. But theoretically it works.
- My plan is to try Rasberry Pi later. Here is a nice [website](https://www.mouser.in/new/ftdi/ftdi-raspberry-pi-interface-modules/) that may be useful. 