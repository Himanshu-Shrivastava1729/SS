/*
============================================================================
Name : 18a.c
Author : Himanshu Shrivastava
Description : Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a fi
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
#include<stdlib.h>
	struct 
        {
                int ID;
                char name[512];
        } info;

int main()
{
	int fd = open("problem18",O_RDWR | O_CREAT,0664);
	if(fd == -1)
	{
		perror("error occured\n");
		return 1;
	}
	int input;
	printf("enter record to be updated between 1 to 3.\n");
	scanf("%d",&input);
	
	struct flock lockInfo1,lockInfo2;
	lockInfo1.l_type = F_WRLCK;
	lockInfo1.l_start = (input-1) * sizeof(info);
	lockInfo1.l_whence = SEEK_SET;
	lockInfo1.l_len = sizeof(info);
	lockInfo1.l_pid = getpid();
	
	lockInfo2 = lockInfo1;

	//first check if any lock exists
	if(fcntl(fd,F_GETLK,&lockInfo1) == -1)
	{
		perror("error while checking lock.\n");
		close(fd);
		return 1;
	}
	else if(lockInfo1.l_type == F_RDLCK)
	{

		printf("read lock already present.waiting...\n");
		while(lockInfo1.l_type == F_RDLCK)
		{
			fcntl(fd,F_GETLK,&lockInfo1);
		}
	}

	if(fcntl(fd,F_SETLKW,&lockInfo2) == -1)
	{
		perror("error while getting write lock\n");
		close(fd);
		return 1;
	}
	printf("Enter info:\n");
	//set offset so that write happens at correct record.
	lseek(fd,(input-1)*sizeof(info),SEEK_SET);
	scanf("%d",&info.ID);
	scanf("%s",info.name);
	write(fd,&info,sizeof(info));
	
	lockInfo2.l_type = F_UNLCK;
	if(fcntl(fd,F_SETLK,&lockInfo1) == -1)
	{
		perror("error while releasing lock\n");
		close(fd);
		return 1;
	}
	close(fd);
	return 0;
}








