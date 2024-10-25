/*
============================================================================
Name : 4.c
Author : Himanshu Shrivastava
Description :Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date: 21 Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>
#include<sys/resource.h>
unsigned long long rdtsc()
{
	unsigned long long dst;
	asm volatile("rdtsc":"=A" (dst));
	return dst;
}
int main()
{
	int i,nanoSec;
	unsigned long long int start,end;
	start = rdtsc();
	for(i=0;i<=100;i++)
	{
		getppid();
	}
	end = rdtsc();

	nanoSec = (end-start) / 4.60;
	printf("getppid() takes %d\n",nanoSec);
	return 0;
}
		
