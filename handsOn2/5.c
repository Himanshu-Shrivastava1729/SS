/*
============================================================================
Name : 5.c
Author : Himanshu Shrivastava
Description :Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
Date: 21 Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/sysinfo.h>

int main() {
	long argExec = sysconf(_SC_ARG_MAX);
	printf("\nmax arg. for exec: %ld",argExec);
	long maxChild = sysconf(_SC_CHILD_MAX);
	printf("\nmax processes per UID: %ld",maxChild);
	long maxClk = sysconf(_SC_CLK_TCK);
	printf("\nTicks per sec: %ld",maxClk);
	long maxOpenFiles = sysconf(_SC_OPEN_MAX);
	printf("\nmax open files: %ld",maxOpenFiles);
	long pgSize = sysconf(_SC_PAGESIZE);
	printf("\npage size: %ld",pgSize);
	long phyPages = sysconf(_SC_PHYS_PAGES);
	printf("\npages in physical memory: %ld",phyPages);
	long avlPages = sysconf(_SC_AVPHYS_PAGES);
	printf("\navailable pages in physical memory: %ld",avlPages);

	return 0;
}


