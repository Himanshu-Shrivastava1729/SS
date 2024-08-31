/*
============================================================================
Name : 9.c
Author : Himanshu Shrivastava
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 31st Aug, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>

int main(int argc,char *argv[])
{
	if(argc != 2)
	{
		printf("give arguments\n");
		return 1;
	}
	char *fileName = argv[1];
	struct stat fileInfo;
	if(stat(fileName,&fileInfo) == -1)
	{
		perror("stat error\n");
		return 1;
	}
	printf("i-node: %ld\n",(long)fileInfo.st_ino);
	printf("Number of hard links: %ld\n",(long)fileInfo.st_nlink);
	printf("uid: %d\n",fileInfo.st_uid);
	printf("gid: %d\n",fileInfo.st_gid);
	printf("size: %ld\n",(long)fileInfo.st_size);
	printf("block size: %ld\n",(long)fileInfo.st_blksize);
	printf("Number of blocks: %ld\n",(long)fileInfo.st_blocks);
	printf("Last access on: %s\n",ctime(&fileInfo.st_atime));
	printf("Last update on: %s\n",ctime(&fileInfo.st_mtime));
	printf("Last change on: %s\n",ctime(&fileInfo.st_ctime));

	return 0;
}
