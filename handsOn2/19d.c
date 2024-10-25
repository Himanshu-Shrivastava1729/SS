/*
============================================================================
Name : 19d.c
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
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>
int main()
{
	const char* file_name = "new_fifo1";
	if(mknod(file_name,S_IFIFO | 0644,0) == -1)
	{
		perror("error");
		exit(1);
	}

	printf("fifo file created\n");
	return 0;
}
