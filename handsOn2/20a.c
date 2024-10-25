/*
============================================================================
Name : 20a.c
Author : Himanshu Shrivastava
Description :Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>
//writer program
int main()
{
	const char* file_path = "fifoIPC";
	const char* message = "from writer to reader";
	mknod(file_path,S_IFIFO | 0644,0);
	int fd1 = open(file_path,O_WRONLY);
	if((write(fd1,message,strlen(message))) == -1)
	{
		perror("write error");
		exit(1);
	}
	close(fd1);
	return 0;
}


