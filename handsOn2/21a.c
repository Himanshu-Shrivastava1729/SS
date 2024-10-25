/*
============================================================================
Name : 21a.c
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
//program 1
int main()
{
	const char* file_path1 = "fifo10";
	const char* file_path2 = "fifo20";
	char wr_buffer[512];
	char rd_buffer[512];
	if(mknod(file_path1,S_IFIFO | 0644,0) == -1)
	{
		perror("mknod1 error");
		exit(1);
	}
	if(mknod(file_path2,S_IFIFO | 0644,0) == -1)
	{
		perror("mknod2 error");
		exit(1);
	}

	//write to fifo 10 and read from fifo20
	int fd_write = open(file_path1,O_WRONLY);
	int fd_read = open(file_path2,O_RDONLY);
	if(fd_write == -1 || fd_read == -1)
	{
		perror("write error");
		exit(1);
	}

	while(1)
	{
		printf("write to send from prog A to prog B\n");
		fgets(wr_buffer,512,stdin);
		write(fd_write,wr_buffer,sizeof(wr_buffer));
		read(fd_read,rd_buffer,sizeof(rd_buffer));
		printf("From prog B to prog A: %s\n",rd_buffer);
	}
	close(fd_write);
	close(fd_read);

	return 0;
}
