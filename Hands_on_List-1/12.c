/*
============================================================================
Name : 12.c
Author : Himanshu Shrivastava
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 31st Aug, 2024.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main()
{

	int fd = open("problem12.txt",O_CREAT | O_RDWR | O_EXCL,0666);
	if(fd == -1)
	{
		perror("open error");
		return 1;
	}
	int res = fcntl(fd,F_GETFL);
	printf("%d\n",res);
	if(res & O_RDONLY)
		printf("read only mode\n");
	if(res & O_RDWR)
		printf("read write mode\n");
	if(res & O_WRONLY)
		printf("write only mode\n");
	return 0;
}
