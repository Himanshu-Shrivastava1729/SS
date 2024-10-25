/*
============================================================================
Name : 28.c
Author : Himanshu Shrivastava
Description :Write a program to change the exiting message queue permission. (use msqid_ds structure)
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
	struct msqid_ds buf;
	key = ftok("/home/himanshu/Desktop/handsOn2", 'A');
	msgid = msgget(key,0666);
	if(msgid == -1)
	{
		perror("error");
		exit(1);
	}
	if(msgctl(msgid,IPC_STAT,&buf) == -1)
	{
		perror("error");
		exit(1);
	}
	printf("queue permission: %o\n",buf.msg_perm.mode);
	buf.msg_perm.mode = 0644;
	if(msgctl(msgid,IPC_SET,&buf) == -1)
	{
		perror("error");
		exit(1);
	}
	if(msgctl(msgid,IPC_STAT,&buf) == -1)
        {
                perror("error");
                exit(1);
        }
        printf("updated queue permission: %o\n",buf.msg_perm.mode);

	return 0;
}
