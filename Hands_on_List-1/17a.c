/*
============================================================================
Name : 17a.c
Author : Himanshu Shrivastava
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 31st Aug, 2024.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include <sys/select.h>
#include<sys/types.h>
#include<sys/file.h>

int main()
{
	int ticketNum = 0;
	int fd = open("problem17.txt",O_RDWR | O_CREAT,0777);
	if(fd == -1)
	{
		perror("open error");
		return 1;
	}
	if((write(fd,&ticketNum,sizeof(ticketNum))) == -1)
	{
		perror("error");
		return 1;
	}
	close(fd);

	return 0;
}
