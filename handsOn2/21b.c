/*
============================================================================
Name : 21b.c
Author : Himanshu Shrivastava
Description :Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include<string.h>

int main()
{
	char rd_buffer[512];
	char wr_buffer[512];

	int fd_read = open("fifo10",O_RDONLY);
	int fd_write = open("fifo20",O_WRONLY);

	while(1)
	{
		read(fd_read,rd_buffer,strlen(rd_buffer));
		printf("data read from A to B: %s\n",rd_buffer);
		printf("enter data to send from B to A:\n");
		fgets(wr_buffer,512,stdin);
		write(fd_write,wr_buffer,strlen(wr_buffer));
	}
	close(fd_read);
	close(fd_write);

	return 0;
}
