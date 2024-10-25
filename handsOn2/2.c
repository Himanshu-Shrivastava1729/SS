/*
============================================================================
Name : 2.c
Author : Himanshu Shrivastava
Description : Write a program to print the system resource limits. Use getrlimit system call.
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

void giveLimit(int val,const char* lim)
{
	struct rlimit rm;
	if(getrlimit(val,&rm) == 0)
	{
		printf("%s softLimit: %ld\n,hardlimit: %ld\n",lim,rm.rlim_cur,rm.rlim_max);
	}
	else
	{
		perror("error\n");
	}
}

int main()
{
	giveLimit(RLIMIT_STACK,"stack");
	giveLimit(RLIMIT_CORE,"core file size");
	giveLimit(RLIMIT_CPU,"cpu");
	giveLimit(RLIMIT_FSIZE,"file size");
	giveLimit(RLIMIT_MEMLOCK,"memory lock");
	giveLimit(RLIMIT_LOCKS,"locks");
	return 0;

}
