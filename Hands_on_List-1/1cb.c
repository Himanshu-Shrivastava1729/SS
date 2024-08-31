/*
============================================================================
Name : 1cb.c
Author : Himanshu Shrivastava
Description : 1. Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 31st Aug, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	if(mknod("./1cbfifo",S_IFIFO | 0666,0) == -1)
	{
		perror("mknod error\n");
		return 1;
	}
	printf("fifo file created\n");
	return 0;
}
