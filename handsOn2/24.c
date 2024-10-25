/*
============================================================================
Name : 24.c
Author : Himanshu Shrivastava
Description :Write a program to create a message queue and print the key and message queue id
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

int main()
{
	key_t key_num;
	int msid;
	key_num = ftok("/home",'D');
	if(key_num == -1)
	{
		perror("error");
		exit(1);
	}
	msid = msgget(key_num,0666 | IPC_CREAT);
	if(msid == -1)
	{
		perror("error");
		exit(1);
	}
	printf("key: %d\n",key_num);
	printf("msgid: %d\n",msid);

	return 0;
}

