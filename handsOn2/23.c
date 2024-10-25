/*
============================================================================
Name : 23.c
Author : Himanshu Shrivastava
Description :Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 21 Sept, 2024.
============================================================================
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
	struct rlimit fdlimit;
	if(getrlimit(RLIMIT_NOFILE,&fdlimit) == -1)
	{
		perror("error");
		exit(1);
	}
	else
	{
		printf("max fds allowed: %ld\n",fdlimit.rlim_cur);
	}
	int pipe_fd[2];

	if(pipe(pipe_fd) == -1)
	{
		perror("pipe error");
		exit(1);
	}
	int psize = fcntl(pipe_fd[0],F_GETPIPE_SZ);
	if(psize == -1)
	{
		perror("error");
	}
	else 
	{
		printf("pipe circulr buffer size: %d\n",psize);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	return 0;
}


