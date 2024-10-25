/*
============================================================================
Name : 14.c
Author : Himanshu Shrivastava
Description :Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include<sys/wait.h>
int main()
{
	int pipefd[2];
	char writebuff[] = "sent from child to parent process\n";
	char readbuff[128];
	if(pipe(pipefd) == -1)
                {
                        perror("error\n");
                        exit(1);
                }

	pid_t pid = fork();
	if(pid == 0)
	{
		//child
		close(pipefd[0]);
		ssize_t wr = write(pipefd[1],writebuff,strlen(writebuff));
		if(wr == -1)
		{
			perror("error\n");
			exit(1);
		}
		close(pipefd[1]);

	}
	else if(pid > 0)
	{
		//parent
		close(pipefd[1]);
		ssize_t rd = read(pipefd[0],readbuff,sizeof(readbuff)-1);
		if(rd == -1)
		{
			perror("error\n");
			exit(1);
		}
		readbuff [rd] = '\0';
		printf("from child : %s",readbuff);
		close(pipefd[0]);
		wait(NULL);
	}
	return 0;
}

