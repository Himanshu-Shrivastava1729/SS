/*
============================================================================
Name : 8.c
Author : Himanshu Shrivastava
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	char buffer[512];
	ssize_t readSize;
	int i = 0;
	int lineEnd = 0;
	int fd = open("/home/himanshu/Desktop/problem8a.txt",O_RDONLY);
	if(fd == -1)
	{
		perror("open error");
		return 1;
	}
	while((readSize = read(fd,buffer,sizeof(buffer))) > 0)
	{
		//printf("%s %ld %s %d\n","read:size: ",readSize,"lineend: ",lineEnd);
		for(i=0;i<readSize;i++)
		{
			//printf("%s %d %s %d\n","i : ",i,"lineEnd: ",lineEnd);
			if(buffer[i] == '\n')
			{
				write(1,buffer+lineEnd,i-lineEnd+1);
				lineEnd = i+1;
			}
		}
		
	}
	close(fd);
	return 0;
}

