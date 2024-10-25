/*
============================================================================
Name : 10.c
Author : Himanshu Shrivastava
Description :Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_signals(int signum,siginfo_t* info,void* context)
{
	if(signum == SIGSEGV)
	{
		printf("caught sigsegv\n");
		printf("sigcode: %d\n",info->si_code);
		printf("addr: %p\n",info->si_addr);
		printf("pid: %d\n",info->si_pid);
		printf("uid: %d\n",info->si_uid);

	}
	else if(signum == SIGINT)
	{
		printf("caught sigint\n");
                printf("sigcode: %d\n",info->si_code);
                printf("addr: %p\n",info->si_addr);
                printf("pid: %d\n",info->si_pid);
                printf("uid: %d\n",info->si_uid);

	}
	else if(signum == SIGFPE)
	{
		printf("caught sigfpe\n");
		printf("sigcode: %d\n",info->si_code);
                printf("addr: %p\n",info->si_addr);
                printf("pid: %d\n",info->si_pid);
                printf("uid: %d\n",info->si_uid);

	}
	exit(1);
}

int main()
{
	struct sigaction sg;
	sg.sa_sigaction = handle_signals;
	//if i don't set this flag then signal handling fucntion will take only one parameter signum.	
	sg.sa_flags = SA_SIGINFO;
	sigemptyset(&sg.sa_mask);
	if(sigaction(SIGSEGV,&sg,NULL) == -1)
	{
		perror("error\n");
		exit(1);
	}
	if(sigaction(SIGINT,&sg,NULL) == -1)
        {       
                perror("error\n");
                exit(1);
        }
        if(sigaction(SIGFPE,&sg,NULL) == -1)
        {
                perror("error\n");
                exit(1);
        }
	//sigsegv generation
//	int* ptr = NULL;
//	*ptr = 52;
//	int fpe = 2/0;
//	printf("val: %d",fpe);
	while(1){}
	return 0;
}
