/*
============================================================================
Name : 25.c
Author : Himanshu Shrivastava
Description : Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
	int c1,c2,c3;
	if(!(c1 = fork()))
	{
		printf("this is child: %d\n",getpid());
		sleep(3);
	}
	else if(!(c2 = fork()))
	{
		printf("this is  child: %d\n",getpid());
		sleep(8);
	}
	else if(!(c3 = fork()))
	{
		printf("this is child: %d\n",getpid());
		sleep(12);
	}
	else
	{
		printf("this is parent: %d,waiting for child: %d\n",getpid(),c3);
		waitpid(c3,NULL,0);
	}
	return 0;
}
