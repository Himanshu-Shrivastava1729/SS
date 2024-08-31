/*
============================================================================
Name : 5.c
Author : Himanshu Shrivastava
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 31st Aug, 2024.
============================================================================
*/

#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int cnt = 0;
	char fileName[30];
	for(;;)
	{
		if(cnt<5)
		{
			sprintf(fileName,"problem5File%d",cnt);
			int fd = creat(fileName,0666);
			if(fd == -1)
			{
				perror("error occured");
				return 1;
			}
			cnt++;
		}
	}
	return 0;
}


/*
  ls -l /proc/10855/fd
total 0
lrwx------ 1 himanshu himanshu 64 Aug 31 17:00 0 -> /dev/pts/0
lrwx------ 1 himanshu himanshu 64 Aug 31 17:00 1 -> /dev/pts/0
lrwx------ 1 himanshu himanshu 64 Aug 31 17:00 2 -> /dev/pts/0
l-wx------ 1 himanshu himanshu 64 Aug 31 17:00 3 -> /home/himanshu/Desktop/MT2024059/problem5File0
l-wx------ 1 himanshu himanshu 64 Aug 31 17:00 4 -> /home/himanshu/Desktop/MT2024059/problem5File1
l-wx------ 1 himanshu himanshu 64 Aug 31 17:00 5 -> /home/himanshu/Desktop/MT2024059/problem5File2
l-wx------ 1 himanshu himanshu 64 Aug 31 17:00 6 -> /home/himanshu/Desktop/MT2024059/problem5File3
l-wx------ 1 himanshu himanshu 64 Aug 31 17:00 7 -> /home/himanshu/Desktop/MT2024059/problem5File4
*/

