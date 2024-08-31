/*
============================================================================
Name : 22.c
Author : Himanshu Shrivastava
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include<sys/types.h>
int main()
{
	int fd = open("problem22.txt",O_WRONLY | O_CREAT,0664);
	if(fd == -1)
	{
		perror("error while opening file\n");
		return 1;
	}

	pid_t pid = fork();
	if(pid < 0)
	{
		perror("fork error\n");
		return 1;
	}
	else if (pid == 0)
	{
		char buffer[512];
		sprintf(buffer,"from child pid: %d",getpid());
		write(fd,buffer,strlen(buffer));
		write(fd,"\n",1);
	}
	else
	{
		char buffer[512];
                sprintf(buffer,"from parent pid: %d",getpid());
                write(fd,buffer,strlen(buffer));
                write(fd,"\n",1);
		int status;
		wait(&status);
	}
	close(fd);
	return 0;
}



