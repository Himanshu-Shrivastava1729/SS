/*
============================================================================
Name : 26.c
Author : Himanshu Shrivastava
Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 31st Aug, 2024.
============================================================================
*/


#include<unistd.h>
#include<stdio.h>

int main()
{
	if(execl("./problem26.out","problem26.out",NULL) == -1)
	{
		perror("execl error\n");
		return 1;
	}
	return 0;
}
