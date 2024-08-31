/*
============================================================================
Name : 6.c
Author : Himanshu Shrivastava
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
Date: 31st Aug, 2024.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>

int main()
{
	char buffer[128];
	ssize_t readSize,writeSize;

	while(1)
	{
		readSize = read(0,buffer,20);
		if(readSize == -1)
		{
			perror("error from read system call");
			return 1;
		}
		if(readSize == 1) break;
		//printf("%ld\n",readSize);
		writeSize = write(1,buffer,readSize);
		if(writeSize == -1)
		{
			perror("errror from write system call");
			return 1;
		}

	}
	return 0;
}


