/*
============================================================================
Name : 23.c
Author : Himanshu Shrivastava
Description : Write a program to create a Zombie state of the running program.
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdlib.h>
int main()
{
	pid_t pid;
	pid = fork();
	if(pid < 0)
	{
		perror("fork error\n");
		return 1;
	}
	else if(pid == 0)
	{
		printf("child process pid : %d\n",getpid());
		_exit(0);
	}
	else
	{
		printf("parent pid : %d\n",getpid());
		sleep(20);
		int status;
		wait(&status);
		printf("parent process will terminate now\n");
	}

	return 0;
}
