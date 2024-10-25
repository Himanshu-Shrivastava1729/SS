/*
============================================================================
Name : 8.c
Author : Himanshu Shrivastava
Description :Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
d. SIGALRM (use alarm system call)
e. SIGALRM (use setitimer system call)
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

void handle_sigsegv(int signum)
{
	printf("caught sigsegv\n");
	exit(1);
}
void handle_sigint(int signum)
{
	printf("caught sigint\n");
	exit(1);
}
void handle_sigfpe(int signum)
{
	printf("caught sigfpe\n");
	exit(1);

}
void handle_sigalrm(int signum)
{
	printf("caught sigalrm\n");
	exit(1);
}
void handle_sigvtalrm(int signum)
{
	printf("caught sigvtalrm\n");
	exit(1);
}
void handle_sigprof(int signum)
{
	printf("caught sigprof\n");
	exit(1);
}

int main()
{
	signal(SIGSEGV,handle_sigsegv);
	signal(SIGINT,handle_sigint);
	signal(SIGFPE,handle_sigfpe);
	signal(SIGALRM,handle_sigalrm);
	signal(SIGVTALRM,handle_sigvtalrm);
	signal(SIGPROF,handle_sigprof);

//	alarm(2);
	struct itimerval it_val;
	it_val.it_value.tv_sec = 2;
	it_val.it_value.tv_usec = 0;
	it_val.it_interval.tv_sec = 0;
	it_val.it_interval.tv_usec = 0;
	setitimer(ITIMER_REAL,&it_val,NULL);

	it_val.it_value.tv_sec = 0;
        it_val.it_value.tv_usec = 600000;
        it_val.it_interval.tv_sec = 0;
        it_val.it_interval.tv_usec = 0;
        setitimer(ITIMER_VIRTUAL,&it_val,NULL);
	
	it_val.it_value.tv_sec = 2;
        it_val.it_value.tv_usec = 0;
        it_val.it_interval.tv_sec = 0;
        it_val.it_interval.tv_usec = 0;
       if(( setitimer(ITIMER_PROF,&it_val,NULL)) == -1)
       {
	       perror("error\n");
	       exit(1);
       }

//	int* node = NULL;
	float it = 5.0/0.0;
//	*node = 68;
	while(1)
	{
	}
	return 0;
}



