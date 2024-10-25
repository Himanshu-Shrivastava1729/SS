/*
============================================================================
Name : 26.c
Author : Himanshu Shrivastava
Description :Write a program to send messages to the message queue. Check $ipcs -q
Date: 21 Sept, 2024.
============================================================================
*/
#include<stdio.h>
#include<sys/msg.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct msg_buff{
	long mtype;
	char mtext[100];
};
int main()
{
	struct msg_buff msg;
	key_t key;
	key = ftok("/home/himanshu/Desktop/handsOn2",'A');
	int msgid = msgget(key,IPC_CREAT | 0666);
	if(msgid == -1)
	{
		perror("error");
		exit(1);
	}
	msg.mtype = 5;
	printf("enter text to send\n");
	fgets(msg.mtext,sizeof(msg.mtext),stdin);

	if(msgsnd(msgid,&msg,sizeof(msg.mtext),0) == -1)
	{
		perror("error");
		exit(1);
	}
	printf("message sent\n");
	return 0;
}

