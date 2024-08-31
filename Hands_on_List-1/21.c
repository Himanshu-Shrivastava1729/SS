/*
============================================================================
Name : 21.c
Author : Himanshu Shrivastava
Description : Write a program, call fork and print the parent and child process id.
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	pid_t pid;
	pid = fork();
	if(pid < 0)
	{
		perror("cannot execute fork\n");
	}
	else if(pid == 0)
	{
		printf("This is child process: %d\n",getpid());
	}
	else
	{
		int status;
		wait(&status);
		printf("This is parent process: %d\n",getpid());
	}
	return 0;
}
