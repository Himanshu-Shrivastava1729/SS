/*
============================================================================
Name : 25.c
Author : Himanshu Shrivastava
Description :Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
#include<stdlib.h>
int main()
{
	struct msqid_ds res;
	key_t key;
	key = ftok("/home/himanshu/Desktop/handsOn2",'A');
	int msgid = msgget(key,0666 | IPC_CREAT);
	if(msgid == -1)
	{
		perror("error");
		exit(1);
	}
	if(msgctl(msgid,IPC_STAT,&res) == -1)
	{
		perror("error");
		exit(1);
	}
	printf("Access permission %o\n",res.msg_perm.mode & 0777);
	printf("UID: %d\n",res.msg_perm.uid);
	printf("GID: %d\n",res.msg_perm.gid);
	printf("last sent msg on: %s\n",ctime(&res.msg_stime));
	printf("last rcv msg on: %s\n",ctime(&res.msg_rtime));
	printf("last change in queue on: %s\n",ctime(&res.msg_ctime));
	printf("size of queue: %lu\n",res.msg_qbytes);
	printf("number of messages in queue: %lu\n",res.msg_qnum);
	printf("max bytes allowed in queue: %lu\n",res.msg_qbytes);
	printf("pid of last sent: %d\n",res.msg_lspid);
	printf("pid of last rcv: %d\n",res.msg_lrpid);
	return 0;
}



