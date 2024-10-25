/*
============================================================================
Name : 30c.c
Author : Himanshu Shrivastava
Description :Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	key_t key;
	int shmid;
	key = ftok("/home/himanshu/Desktop/handsOn2",'B');
	shmid = shmget(key,1024,0666 | IPC_CREAT);
	if(shmid == -1)
	{
		perror("error");
		exit(1);
	}
	char* shmaddr = (char*)shmat(shmid,NULL,SHM_RDONLY);
	if(shmdt(shmaddr) == -1)
	{
		perror("error");
		exit(1);
	}
	printf("shared memory detached\n");
	return 0;
}
