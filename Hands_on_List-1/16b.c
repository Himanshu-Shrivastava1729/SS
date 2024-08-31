/*
============================================================================
Name : 16b.c
Author : Himanshu Shrivastava
Description : Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
Date: 31st Aug, 2024.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include <sys/select.h>
#include<sys/types.h>
#include<sys/file.h>
int main()
{
        int fd = open("problem16a.txt",O_CREAT | O_RDWR,0666);
        struct flock lockInfo1,lockInfo2;
        lockInfo1.l_type = F_WRLCK;
        lockInfo1.l_whence = SEEK_SET;
        lockInfo1.l_start = 0;
        lockInfo1.l_len = 0;
        lockInfo2 = lockInfo1;
        fcntl(fd,F_GETLK,&lockInfo1);

        if(lockInfo1.l_type == F_RDLCK)
        {
                printf("process has READ lock..wait\n");
                while(lockInfo1.l_type == F_RDLCK)
                {
                        fcntl(fd,F_GETLK,&lockInfo1);
                }
        }
        if(fcntl(fd,F_SETLKW,&lockInfo2) == -1)
        {
                perror("error while acquiring lock\n");
        }
        printf("Entering critical section\n");
        printf("press Enter to release lock and come out of critical section\n");
        getchar();
        lockInfo2.l_type = F_UNLCK;
        if(fcntl(fd,F_SETLK,&lockInfo2) == -1)
        {
                perror("error");
                close(fd);
                return 1;
        }
        printf("lock released,out of critical section");
        close(fd);

        return 0;
}

