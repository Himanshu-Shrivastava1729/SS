/*
============================================================================
Name : 27a.c
Author : Himanshu Shrivastava
Description :Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

struct msg_buff
{
	long mtype;
	char mtext[100];
};
int main()
{
	struct msg_buff msg;
	key_t key;
	int msgid;
	key = ftok("/home/himanshu/Desktop/handsOn2",'A');
	msgid = msgget(key,0666);
	if(msgid == -1)
	{
		perror("error");
		exit(1);
	}
	if(msgrcv(msgid,&msg,sizeof(msg.mtext),5,0) == -1)
	{
		perror("error");
		exit(1);
	}
	printf("msg received: %s\n",msg.mtext);
	return 0;
}
