/*
============================================================================
Name : 13a.c
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

void handle_signal(int signum)
{
	printf("caught SIGSTOP(not possible)\n");
}

int main()
{
	signal(SIGSTOP,handle_signal);
	int pid = getpid();
	printf("pid: %d\n",pid);
	printf("waiting for sigstop\n");
	while(1){}

	return 0;
}