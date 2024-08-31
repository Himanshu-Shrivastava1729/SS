/*
============================================================================
Name : 15.c
Author : Himanshu Shrivastava
Description : Write a program to display the environmental variable of the user (use environ).
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>

int main()
{
	extern char **environ;
	char **res = environ;

	while(*res != NULL)
	{
		printf("\n%s",*res);
		res++;
	}
	return 0;
}
