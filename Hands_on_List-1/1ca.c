/*
============================================================================
Name : 1ca.c
Author : Himanshu Shrivastava
Description : 1. Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	//creating FIFO file using mkfifo lib function.
	if(mkfifo("./1cfifo",0666) == -1)
	{
		perror("mkfifo error\n");
		return 1;
	}
	printf("fifo file created\n");
	return 0;
}
