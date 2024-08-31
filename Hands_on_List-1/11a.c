/*
============================================================================
Name : 11a.c
Author : Himanshu Shrivastava
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 31st Aug, 2024.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	int fdOld = open("problem11a.txt",O_CREAT | O_RDWR,0666);
	if(fdOld == -1)
	{
		perror("open error");
		return 1;
	}
	int fdNew = dup(fdOld);
	if(write(fdOld,"problem11oldFd",14) == -1)
	{
		perror("write error1");
		return 1;
	}
	if(write(fdNew,"problem11newFd",14) == -1)
	{
                perror("write error2");
                return 1;
        }
	close(fdOld);
	close(fdNew);
	return 0;
}
