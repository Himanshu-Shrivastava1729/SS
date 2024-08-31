/*
============================================================================
Name : 27a.c
Author : Himanshu Shrivastava
Description : Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execled. execv
e. execvp
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
	if(execl("/bin/ls","-R","-l",NULL) == -1)
	{
		perror("error occured\n");
		return 1;
	}
	return 0;
}
