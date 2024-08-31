/*
============================================================================
Name : 28.c
Author : Himanshu Shrivastava
Description : Write a program to get maximum and minimum real time priority.
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdlib.h>
#include<stdio.h>
#include<sched.h>
#include<sys/resource.h>
int main()
{
	int minPriorityFIFO = sched_get_priority_min(SCHED_FIFO);
	int maxPriorityFIFO = sched_get_priority_max(SCHED_FIFO);
	//int minNonRealTime = sched_get_priority_min(SCHED_OTHER);
	//int maxNonRealTime = sched_get_priority_max(SCHED_OTHER);
	printf("Real Time min: %d max: %d\n",minPriorityFIFO,maxPriorityFIFO);
	//printf("Non Real Time min: %d max: %d\n",minNonRealTime,maxNonRealTime);
	return 0;
}

