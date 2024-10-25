/*
============================================================================
Name : 7.c
Author : Himanshu Shrivastava
Description :Write a simple program to print the created thread ids.
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void* threadFunction(void* thread_id)
        {       pthread_t tid = pthread_self();
                printf("running thread %lu",tid);
                pthread_exit(NULL);
        }

int main()
{
	pthread_t thread[3];
	for(long t=0;t<3;t++)
	{
		int rs = pthread_create(&thread[t],NULL,threadFunction,(void*)t);
		if(rs != 0)
		{
			perror("thread error\n");
		}
	}
	for(long t=0;t<3;t++)
	{
		int rs = pthread_join(thread[t],NULL);
		if(rs != 0)
		{
			perror("thread join error\n");
		}
	}
	return 0;
}



