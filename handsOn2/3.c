/*
============================================================================
Name : 3.c
Author : Himanshu Shrivastava
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/resource.h>

int main()
{
	struct rlimit rm;
	if(getrlimit(RLIMIT_STACK,&rm) == 0)
	{
		printf("current soft limit: %ld,current hardlimit: %ld",rm.rlim_cur,rm.rlim_max);

	}
	else
	{
		perror("error");
	}
	rm.rlim_cur = 8388600;
       if(setrlimit(RLIMIT_STACK,&rm) == 0)
       {
		if(getrlimit(RLIMIT_STACK,&rm) == 0)
		{
			printf("new soft limit: %ld, hardlimit: %ld",rm.rlim_cur,rm.rlim_max);
		}
       }
	else
	{
		perror("error");
	}
	return 0;
}	
