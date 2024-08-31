/*
============================================================================
Name : 17b.c
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
	int ticketNum;
	int fd = open("problem17.txt",O_RDWR);
	if(fd == -1)
	{
		perror("open error");
		return 1;
	}
	struct flock lockInfo1;
	lockInfo1.l_type = F_WRLCK;
	lockInfo1.l_whence = SEEK_SET;
	lockInfo1.l_start = 0;
	lockInfo1.l_len = 0;
	if(fcntl(fd,F_SETLKW,&lockInfo1) == -1)
	{
		perror("error");
		return 1;
	}
	if((read(fd,&ticketNum,sizeof(ticketNum))) == -1)
	{
		perror("read error");
		return 1;
	}
	ticketNum++;
	lseek(fd,0,SEEK_SET);

	if((write(fd,&ticketNum,sizeof(ticketNum)))==-1)
	{
		perror("write error");
		return 1;
	}
	printf("New ticket Num: %d\n",ticketNum);

	lockInfo1.l_type = F_UNLCK;
	if(fcntl(fd,F_SETLKW,&lockInfo1) == -1)
	{
		perror("error");
		close(fd);
		return 1;
	}
	close(fd);

	return 0;
}

