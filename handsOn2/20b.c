/*
============================================================================
Name : 20b.c
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

int main()
{
	char buffer[1024];
	int fd = open("fifoIPC",O_RDONLY);
	read(fd,buffer,sizeof(buffer));

	printf("data received: %s\n",buffer);
	return 0;
}
