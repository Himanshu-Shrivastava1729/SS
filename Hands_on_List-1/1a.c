/*
============================================================================
Name : 1a.c
Author : Himanshu Shrivastava
Description : 1. Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 31st Aug, 2024.
============================================================================
*/

/*
  ln -s target.txt newSoftLink.txt
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	char fl1[] = "softlinkfile1";
	char fl2[] = "softlinkfile2";

	FILE *fl = fopen(fl1,"w");
	if(fl == NULL)
	{
		perror("error!");
		return 1;
	}
	fprintf(fl,"this is example of softlink");
	fclose(fl);

	if(symlink(fl1,fl2) != 0)
	{
		perror("error!");
		return 1;
	}

	return 0;
}
