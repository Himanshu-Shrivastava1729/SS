/*
============================================================================
Name : 19e.c
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
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include<stdlib.h>
int main()
{
	const char* file_path = "new_fifo2";
	if(mkfifo(file_path,0644) == -1)
	{
		perror("error");
		exit(1);
	}
	printf("fifo created using mkfifo");
	return 0;
}
