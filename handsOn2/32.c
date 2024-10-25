/*
============================================================================
Name : 32.c
Author : Himanshu Shrivastava
Description :Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include<string.h>
union semun
{
	int val;
	struct semid_ds* semid_buff;
	unsigned short* semarr;

};
void sem_wait(int semid)
{
	struct sembuf semwt = {0,-1,0};
	if(semop(semid,&semwt,1) == -1)
	{
		perror("error");
		exit(1);
	}
}
void sem_signal(int semid)
{
	struct sembuf semsig = {0,1,0};
	if(semop(semid,&semsig,1) == -1)
	{
		perror("erroe");
		exit(1);
	}
}
int generate_binary_sema(key_t key)
{	union semun bin_sema;
	bin_sema.val = 1;
	int semid = semget(key,1,0666 | IPC_CREAT);
	if(semid == -1)
	{
		perror("error bin_sem");
	}
	if(semctl(semid,0,SETVAL,bin_sema) == -1)
	{
		perror("Error");
		exit(1);
	}
	return semid;
}
int generate_counting_sema(key_t key)
{
	union semun cnt_sema;
	cnt_sema.val = 3;
	int semid = semget(key,1,0666 | IPC_CREAT);
	if(semid == -1)
        {
                perror("error cnt sem");
        }

	if(semctl(semid,0,SETVAL,cnt_sema) == -1)
	{
		perror("error");
		exit(1);
	}
	return semid;
}
void ticket_number(int semid)
{
	static int ticket_num = 0;
	sem_wait(semid);
	ticket_num++;
	printf("ticket number: %d\n",ticket_num);
	sem_signal(semid);
}
void shared_mem(int semid,int shmid)
{
	char* shmaddr;
	sem_wait(semid);
	shmaddr = (char*)shmat(shmid,NULL,0);
	if(shmaddr == (char*)-1)
	{
		perror("error");
	}
	strncpy(shmaddr,"writing to shared memory",32);
	printf("data written: %s\n",shmaddr);
	if(shmdt(shmaddr) == -1)
	{
		perror("error");
	}
	sem_signal(semid);
}
void pseudo_resources(int semid,int res_id)
{
	sem_wait(semid);
	printf("pseudo resources\n");
	sleep(5);
	sem_signal(semid);
}


int main()
{
	key_t key_bin,key_cnt,key_shm;
	int bin_semid,cnt_semid,shmid;
	union semun sem_union;
	key_bin = ftok("/home/himanshu/Desktop",'G');
	key_cnt = ftok("/home/himanshu/Desktop",'H');
	key_shm = ftok("/home/himanshu/Desktop",'I');
	bin_semid = generate_binary_sema(key_bin);
	cnt_semid = generate_counting_sema(key_cnt);
	shmid = shmget(key_shm,2048,0666 | IPC_CREAT);
	if(shmid == -1)
	{
		perror("error");
		exit(1);
	}
	printf("calling ticket creation function\n");
	ticket_number(bin_semid);
	ticket_number(bin_semid);
	printf("writing in shared memory\n");
	shared_mem(bin_semid,shmid);
	printf("pseudo resource\n");
	pseudo_resources(cnt_semid,1);
	pseudo_resources(cnt_semid,2);
	pseudo_resources(cnt_semid,3);
	if(semctl(bin_semid,0,IPC_RMID) == -1)
	{
		perror("error");
	}
	if(semctl(cnt_semid,0,IPC_RMID) == -1)
	{
		perror("error");
	}
	if(shmctl(shmid,IPC_RMID,NULL) == -1)
	{
		perror("error");
	}	
	return 0;
}
	
	
	
