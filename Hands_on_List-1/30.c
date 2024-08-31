/*
============================================================================
Name : 30.c
Author : Himanshu Shrivastava
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	pid_t pid;
	pid = fork();
	if(pid == 0)
	{
		//pid 0 means child process is running now
		setsid();
		chdir("/");
		umask(0);
		while(1)
		{
			sleep(5);
			printf("child pid: %d\n",getpid());
		}
	}
	else
	{
		exit(0);
	}
	return 0;
}


