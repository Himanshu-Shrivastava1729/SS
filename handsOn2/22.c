/*
============================================================================
Name : 22.c
Author : Himanshu Shrivastava
Description :Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main()
{
	fd_set readfds;
	struct timeval time;
	if(mkfifo("fifo22",0644) == -1)
	{
		perror("mkfifo error");
		exit(1);
	}
	int fd = open("fifo22",O_RDONLY | O_NONBLOCK);
	time.tv_sec = 10;
	time.tv_usec = 0;
	FD_ZERO(&readfds);
	FD_SET(fd,&readfds);

	int res = select(fd+1,&readfds,NULL,NULL,&time);
	if(res == -1)
	{
		perror("error");
		exit(1);
	}
	else if(res == 0)
	{
		printf("timeout after 10 sec");
		exit(1);
	}
	else
	{
		if(FD_ISSET(fd,&readfds))
		{
			char read_buffer[1024];
			read(fd,read_buffer,sizeof(read_buffer));
			printf("data read: %s\n",read_buffer);
		}
	}
	close(fd);
	return 0;
}
