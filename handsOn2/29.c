/*
============================================================================
Name : 29.c
Author : Himanshu Shrivastava
Description :Write a program to remove the message queue.
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

int main()
{
	key_t key;
	int msgid;
	key = ftok("/home/himanshu/Desktop/handsOn2", 'A');
	msgid = msgget(key,0666);
	if(msgid == -1)
	{
		perror("error");
		exit(1);
	}
	if(msgctl(msgid,IPC_RMID,NULL) == -1)
	{
		perror("eror");
		exit(1);
	}
	return 0;
}
