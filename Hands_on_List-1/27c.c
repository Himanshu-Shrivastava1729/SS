/*
============================================================================
Name : 27c.c
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
	char *newEnvVar[] = {"VARIABLE1=PROBLEM27","VARIABLE2=SS",NULL};
	if(execle("/bin/ls","-R","-l",NULL,newEnvVar) == -1)
	{
		perror("error occured\n");
		return 1;
	}
	return 0;
}
