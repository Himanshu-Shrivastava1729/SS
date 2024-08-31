/*
============================================================================
Name : 7.c
Author : Himanshu Shrivastava
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	char buffer[256];
	int fd1 = open("/home/himanshu/Desktop/problem7a.txt",O_RDONLY);
	printf("%d\n",fd1);
	int readSize = read(fd1,buffer,128);
	if(readSize == -1)
	{
		perror("read error");
		return 1;
	}
	int fd2 = open("/home/himanshu/Desktop/problem7b.txt",O_RDWR);
	printf("%d\n",fd2);
	int writeSize = write(fd2,buffer,readSize);
	if(writeSize == -1)
	{
		perror("write error");
		return 1;
	}
	return 0;
}


