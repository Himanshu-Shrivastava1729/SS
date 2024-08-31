/*
============================================================================
Name : 4b.c
Author : Himanshu Shrivastava
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 31st Aug, 2024.
============================================================================
*/

#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
	int fileDescriptorValue = open("newfile4",O_RDWR);

	if(fileDescriptorValue == -1)
	{
		perror("error occured");
		return 1;
	}
	printf("%d\n",fileDescriptorValue);
	return 0;
}

