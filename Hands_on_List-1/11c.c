/*
============================================================================
Name : 11c.c
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
	int fdOld = open("problem11c.txt",O_CREAT|O_RDWR,0666);
	int fdNew = fcntl(fdOld,F_DUPFD,0);
	if(write(fdOld,"sample for problem 11",21) == -1)
	{
		perror("write1 error");
		return 1;
	}
	if(write(fdNew,"sample for problem 11",21) == -1)
        {
                perror("write2 error");
                return 1;
        }
	printf("old fd : %d\n new fd: %d\n",fdOld,fdNew);
	close(fdOld);
	close(fdNew);
	return 0;
}

			

