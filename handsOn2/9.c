/*
============================================================================
Name : 9.c
Author : Himanshu Shrivastava
Description :Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
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
void sigint_default(int signum)
{
	signal(SIGINT,SIG_DFL);
	printf("cannot ignore sigint now\n");
}

int main()
{
	signal(SIGINT,handle_sigint);
	printf("sigint is being ignored,try pressing ctrl+c\n");
	sleep(10);
	printf("setting sigint to it's default behaviour,now press ctrl+c\n");
	sigint_default(SIGINT);
	sleep(10);
	return 0;
}
