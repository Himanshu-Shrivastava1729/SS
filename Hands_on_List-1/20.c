/*
============================================================================
Name : 20.c
Author : Himanshu Shrivastava
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>
#include<sys/resource.h>
int main()
{
	int currPid = getpid();
	int currPriority = getpriority(PRIO_PROCESS,currPid);
	printf("current priority: %d\n",currPriority);

	if(nice(7) == -1)
	{
		perror("error");
		return 1;
	}
	int newPriority = getpriority(PRIO_PROCESS,currPid);
	printf("new priority : %d\n",newPriority);
	return 0;
}


