/*
============================================================================
Name : 19b.c
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



mkfifo fifo1

mkfifo -m 0666 fifo1
