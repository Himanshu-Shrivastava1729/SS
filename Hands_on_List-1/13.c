/*
============================================================================
Name : 13.c
Author : Himanshu Shrivastava
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 31st Aug, 2024.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include <sys/select.h>

int main()
{
	fd_set reqSet;
	struct timeval delayTime;
	delayTime.tv_sec = 10;
	delayTime.tv_usec = 0;
	FD_ZERO(&reqSet);
	FD_SET(STDIN_FILENO,&reqSet);

	int res = select(STDIN_FILENO+1,&reqSet,NULL,NULL,&delayTime);

	if(res == -1) 
	{
		perror("error occured");
		return 1;
	}
	if(res == 0)
	{
		printf("no data passed");
		return 1;
	}
	if(res > 0)
	{
		char inputPassed[1024];
		fgets(inputPassed,sizeof(inputPassed),stdin);
		printf("%s\n",inputPassed);
	}
	return 0;
}
