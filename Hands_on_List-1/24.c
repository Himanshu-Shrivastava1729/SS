/*
============================================================================
Name : 24.c
Author : Himanshu Shrivastava
Description : Write a program to create an orphan process.
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
	pid_t pid;
	pid = fork();

	if(pid < 0)
	{
		perror("fork error\n");
		exit(1);
	}
	else if(pid == 0)
	{
		printf("this is child process,id: %d\n",getpid());
		sleep(5);
		printf("Now child will die");
	}
	else
	{
		printf("This is parent,id: %d\n",getpid());
		printf("now parent will terminate abnormally,making child process orphan\n");
		exit(1);
	}
	return 0;
}
