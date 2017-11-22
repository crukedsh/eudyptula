# Task 3

## Problem

The task for this round is to take the kernel git tree from Task 2 and modify the `Makefile` as well as the
`EXTRAVERSION` field. Do this in a way that the running kernel (after modifying the `Makefile`, rebuilding,
and rebooting) displays "ve482hobby" in the version string. Prepare a patch for the modified `Makefile`.

*Hint:* refer to the file `Documentation/SubmittingPatches`.



## Solution

### File Description

- `extraversion.patch`: A patch containing task-oriented changes.
- `README.md`: This file as readme.





### Environment

This task is complete on Debian GNU/Linux 9 with Linux kernel version 4.12.0.



### Procedure

1. Backup the original source, and create a working archive with `cp` named as `linux-4.12-modf`.
2. `vim linux-4.12-modf/Makefile` and change `EXTRAVERSION` to "ve482hobby".
3. `diff -uprN -X linux-4.12-modf/Documentation/dontdiff linux-4.12-modf linux-4.12 > extraversion.patch` to generate a patch.
4. Build, install and build the modified source.




### Verification

1. Under source directory, `patch -R -p1 < ../extraversion.patch`. Notice the output information as `patching file Makefile`.
2. Build, install and build the modified source, and observe the resulting kernel name as `4.12.0ve482hobby` with `uname -r`.

