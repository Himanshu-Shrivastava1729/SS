/*
============================================================================
Name : 13b.c
Author : Himanshu Shrivastava
Description :Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	printf("pid of process which will receive sigstop:\n");
	scanf("%d",&pid);
	printf("sending SIGSTOP to pid: %d\n",pid);
	if(kill(pid,SIGSTOP) == -1)
	{
		perror("kill error\n");
		exit(1);
	}

	printf("SIGSTOP sent to pid: %d\n",pid);
	sleep(5);
	if(kill(pid,SIGCONT) == -1)
	{
		perror("sigcont error\n");
		exit(1);
	}
	printf("SIGCONT sent to pid: %d\n",pid);
	return 0;
}
