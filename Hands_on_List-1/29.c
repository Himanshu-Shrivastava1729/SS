/*
============================================================================
Name : 29.c
Author : Himanshu Shrivastava
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdlib.h>
#include<stdio.h>
#include<sched.h>
#include<sys/resource.h>
int main()
{
	switch(sched_getscheduler(0))
	{
		case SCHED_FIFO:
			printf("policy used:FIFO\n");
			break;
		case SCHED_RR:
			printf("policy used:Round Robin\n");
			break;
		case SCHED_OTHER:
			printf("policy used:Other\n");
			break;
		default:
			printf("Unknown\n");
	}
	struct sched_param param;
	param.sched_priority = 99;
	if(sched_setscheduler(0,SCHED_FIFO,&param) == -1)
	{
		perror("error occured\n");
		return 0;
	}
	printf("policy set to FIFO with priority: %d\n",getpriority(PRIO_PROCESS,0));
	return 0;
}


