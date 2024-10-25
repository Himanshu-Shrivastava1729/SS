/*
============================================================================
Name : 17c.c
Author : Himanshu Shrivastava
Description :Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<fcntl.h>
int main()
{
	int pipe_fd[2];
	pid_t pid;
	if(pipe(pipe_fd) == -1)
	{
		perror("pipe error");
		exit(1);
	}
	pid = fork();
	if(pid == 0)
	{
		//child
		close(pipe_fd[0]);
		//assigning pipe_fd[1] to stdout(1).
		close(STDOUT_FILENO);
		fcntl(pipe_fd[1],F_DUPFD,STDOUT_FILENO);
		close(pipe_fd[1]);
		//now whatever is supposed to be output on terminal will go to pipe.
		execlp("ls","ls","-l",NULL);
	}
	else if(pid > 0)
	{
		close(pipe_fd[1]);
		close(STDIN_FILENO);
		if((fcntl(pipe_fd[0],F_DUPFD,STDIN_FILENO)) == -1)
		{
			perror("fcntl parent error");
			exit(1);
		}
		close(pipe_fd[0]);
		execlp("wc","wc",NULL);
	}
	return 0;
}



							

