/*
============================================================================
Name : 19c.c
Author : Himanshu Shrivastava
Description :Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
Date: 21 Sept, 2024.
============================================================================
*/

strace mkfifo fi1
execve("/usr/bin/mkfifo", ["mkfifo", "fi1"]
mknodat(AT_FDCWD, "fi1", S_IFIFO|0666)


strace mknod fi2 -p
execve("/usr/bin/mknod", ["mknod", "fi2", "-p"]

mkfifo uses mknod system call.
So mknod is better.


