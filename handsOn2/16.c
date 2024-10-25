/*
============================================================================
Name : 16.c
Author : Himanshu Shrivastava
Description :Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include<stdlib.h>
int main()
{
	int child_to_parent[2];
	int parent_to_child[2];

	if(pipe(child_to_parent) == -1)
	{
		perror("error pipe1\n");
		exit(1);
	}
	if(pipe(parent_to_child) == -1)
	{
		perror("error pipe2\n");
		exit(1);
	}

	pid_t pid = fork();
	if(pid == 0)
	{
		//child
		char c_to_p[] = "from child to parent";
		char p_to_c[128];
		close(child_to_parent[0]);
		close(parent_to_child[1]);

		int wr = write(child_to_parent[1],c_to_p,strlen(c_to_p)+1);
		int rd = read(parent_to_child[0],p_to_c,sizeof(p_to_c));

		printf("inside child process: %s\n",p_to_c);
		close(parent_to_child[0]);
		close(child_to_parent[1]);
	}
	else if(pid > 0)
	{
		//parent
		char p_to_c[] = "from parent to child";
		char c_to_p[128];
		close(parent_to_child[0]);
		close(child_to_parent[1]);

		int wr = write(parent_to_child[1],p_to_c,strlen(p_to_c)+1);
		int rd = read(child_to_parent[0],c_to_p,sizeof(c_to_p));

		printf("inside parent process: %s\n",c_to_p);
		close(parent_to_child[1]);
		close(child_to_parent[0]);
	}
	return 0;
}
