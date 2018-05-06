# Task 10

## Problem

For this task, go back to the "linux-next" tree from task 7. Update it, and then do the following:

- Create a patch that fixes one coding style problem in any of the files from `drivers/staging/`
- Submit the code to the maintainer of the driver/subsystem.

*Hints:* remember the `checkpatch.pl` script to ensure the correctness of the patch; finding the proper
name and mailing lists to send it to can be done by running `scripts/get_maintainer.pl` on the patch.

*Note:* if this patch is accepted into the kernel tree, you become an "official" kernel developer!



## Solution

### File Description

- `extraversion.patch`: A patch containing task-oriented changes.
- `README.md`: This file as readme.



### Environment

This task is conducted on Ubuntu 16.04 LTS with Linux kernel version 4.13.0.



### Procedure

1. Spot the coding style problem in `drivers/staging/vc04_services/interface/vchi/message_drivers/message.h`.

2. Backup the original source, and create a working archive with `cp` named as `linux-4.17-rc3-modf`.

3. `vim linux-4.17-rc3-modf/drivers/staging/vc04_services/interface/vchi/message_drivers/message.h` and change the codings.

4. `diff -uprN -X linux-4.17-rc3-modf/Documentation/dontdiff linux-4.17-rc3 linux-4.17-rc3-modf > 0001-staging-vc04-interface-fix-indentation.patch` to generate a patch.

5. Add the signature in the first line.

   ```
   Signed-off-by: Zhengyang Feng <crukedshfeng@gmail.com>
   ```

6. `perl linux-4.17-rc3/scripts/checkpatch.pl 0001-staging-vc04-interface-fix-indentation.patch` to check the correctness.

7. Submit the patch via email.

### Verification

1. Under source directory, `patch -p1 < ../0001-staging-vc04-interface-fix-indentation.patch`. Notice the output information as `patching file drivers/staging/vc04_services/interface/vchi/message_drivers/message.h`.

## Trivia

- Using `git format-patch` is a more professional way to create a patch. But it takes too long for me to download the whole linux source tree, so I used bare `diff` to avoid hash conflict in the remote source tree.