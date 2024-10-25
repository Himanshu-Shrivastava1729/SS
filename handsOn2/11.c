/*
============================================================================
Name : 11.c
Author : Himanshu Shrivastava
Description :Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int signum)
{
	printf("ignore sigint\n");
}

int main()
{
	struct sigaction sg;
	sg.sa_handler = handle_sigint;
	sg.sa_flags = 0;
	sigemptyset(&sg.sa_mask);
	sigaction(SIGINT,&sg,NULL);
	printf("sigint is being ignored,try pressing ctrl+c\n");
	sleep(10);
	printf("setting sigint to it's default behaviour,now press ctrl+c\n");
	sg.sa_handler = SIG_DFL;
	sigaction(SIGINT,&sg,NULL);
	sleep(10);
	return 0;
}
