/*
============================================================================
Name : 1a.c
Author : Himanshu Shrivastava
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF
Date: 21 Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
void handle_signal(int sg)
{
	printf("timer has expired\n");
}
int main()
{
	signal(SIGALRM,handle_signal);
	struct itimerval timer;
	
	timer.it_value.tv_sec = 5;
	timer.it_value.tv_usec = 5;
	timer.it_interval.tv_sec = 5;
	timer.it_interval.tv_usec = 5;

	if(setitimer(ITIMER_REAL,&timer,NULL) == -1)
	{
		perror("timer error");
		return 1;
	}

	while(1){}
	return 0;
}
