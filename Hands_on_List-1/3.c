/*
============================================================================
Name : 3.c
Author : Himanshu Shrivastava
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
int main()
{
	int fd = creat("newfile",0666);

	if(fd < 0)
	{
		perror("error!");
		return 1;
	}

	printf("%d\n",fd);

	return 0;
}

