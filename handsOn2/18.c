/*
============================================================================
Name : 18.c
Author : Himanshu Shrivastava
Description :Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int pipe_ls[2];
	int pipe_grep[2];
	pipe(pipe_ls);
	pipe(pipe_grep);
	pid_t pid_ls = fork();
	//child will run ls and grep,parent will run final cmnd wc.Sequence is important as only parent can wait for children.
	if(pid_ls == 0)
	{
		close(pipe_ls[0]);
		close(pipe_grep[0]);
		close(pipe_grep[1]);
//		close(STDOUT_FILENO);
		dup2(pipe_ls[1],STDOUT_FILENO);
		close(pipe_ls[1]);
		execlp("ls","ls","-l",NULL);
	}
	pid_t pid_grep = fork();
	if(pid_grep == 0)
	{
		close(pipe_ls[1]);
		close(STDIN_FILENO);
		dup2(pipe_ls[0],STDIN_FILENO);
		close(pipe_ls[0]);
		close(STDOUT_FILENO);
		close(pipe_grep[0]);
		dup2(pipe_grep[1],STDOUT_FILENO);
		close(pipe_grep[1]);
		execlp("grep","grep","^d",NULL);
	}
	close(pipe_ls[0]);
	close(pipe_ls[1]);
//	close(pipe_grep[0]);
	close(pipe_grep[1]);
	dup2(pipe_grep[0],STDIN_FILENO);
	close(pipe_grep[0]);
	execlp("wc","wc","-l",NULL);
	wait(NULL);
	wait(NULL);
//	wait(NULL);

	return 0;
}


	
