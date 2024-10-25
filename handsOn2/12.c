/*
============================================================================
Name : 12.c
Author : Himanshu Shrivastava
Description :Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main()
{
	pid_t pid = fork();
	if(pid < 0)
	{
		perror("fork error\n");
		exit(1);
	}

	if(pid == 0)
	{
		//child process.
		printf("child process id: %d\n",getpid());
		printf("child killing parent process id: %d\n",getppid());
		if(kill(getppid(),SIGKILL) == -1)
		{
			perror("error");
			exit(1);
		}
	}
	else if(pid > 0)
	{
		//parent
		printf("inside parent pid: %d\n",getpid());
	        sleep(10);
	}
	return 0;

}	
