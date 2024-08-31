/*
============================================================================
Name : 1b.c
Author : Himanshu Shrivastava
Description : 1. Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 31st Aug, 2024.
============================================================================
*/

/*
  ln target.txt newHardLink.txt
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	char fl1[] = "hardlinkfile1";
	char fl2[] = "hardlinkfile2";
	FILE *fl = fopen(fl1,"w");
	if(fl == NULL)
	{
		perror("error in creating file");
		return 1;
	}
	fprintf(fl,"example of hard link");
	fclose(fl);

	if(link(fl1,fl2) != 0)
	{
		perror("error!");
		return 1;
	}

	return 0;
}


