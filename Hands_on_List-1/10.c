/*
============================================================================
Name : 10.c
Author : Himanshu Shrivastava
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 31st Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main()
{
	int openFile = open("problem10a.txt",O_CREAT|O_RDWR,0666);
	if(openFile == -1)
	{
		perror("open error");
		return 1;
	}
	char str[32] = "this is it";
	if(write(openFile,str,strlen(str)) == -1)
	{
		perror("write error1");
		return 1;
	}
	int newOffset = lseek(openFile,10,SEEK_CUR);
	char newData[32] = "more data!";
	if(write(openFile,newData,strlen(newData)) == -1)
        {
                perror("write error2");
                return 1;
        }
	printf("offset value :  %d\n", newOffset);
	return 0;
}

/*
od -c problem10a.txt
0000000   t   h   i   s       i   s       i   t  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   m   o   r   e       d   a   t   a   !
0000036

*/


