/*
============================================================================
Name : 31a.c
Author : Himanshu Shrivastava
Description :Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <errno.h>
union semun
{
	int val;
	struct semid_ds* sembuff;
	unsigned short* semar;
};
int main()
{
	key_t key;
	int semid;
	union semun sem;
	key = ftok("/home/himanshu/Desktop",'C');
	semid = semget(key,1,0666 | IPC_CREAT);
	if(semid == -1)
	{
		perror("error");
		exit(1);
	}
	sem.val = 1;
	if(semctl(semid,0,SETVAL,sem) == -1)
	{
		perror("Error");
		exit(1);
	}
	printf("binary semaphore creted");
	return 0;
}
