/*
============================================================================
Name : 2.c
Author : Himanshu Shrivastava
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
Date: 31st Aug, 2024.
============================================================================
*/
int main()
{
	for(;;);

}



/*
ls -l /proc/10746
total 0
-r--r--r--  1 himanshu himanshu 0 Aug 31 16:58 arch_status
dr-xr-xr-x  2 himanshu himanshu 0 Aug 31 16:58 attr
-rw-r--r--  1 himanshu himanshu 0 Aug 31 16:58 autogroup
-r--------  1 himanshu himanshu 0 Aug 31 16:58 auxv
-r--r--r--  1 himanshu himanshu 0 Aug 31 16:58 cgroup
--w-------  1 himanshu himanshu 0 Aug 31 16:58 clear_refs
-r--r--r--  1 himanshu himanshu 0 Aug 31 16:58 cmdline
-rw-r--r--  1 himanshu himanshu 0 Aug 31 16:58 comm
-rw-r--r--  1 himanshu himanshu 0 Aug 31 16:58 coredump_filter
-r--r--r--  1 himanshu himanshu 0 Aug 31 16:58 cpu_resctrl_groups
-r--r--r--  1 himanshu himanshu 0 Aug 31 16:58 cpuset
lrwxrwxrwx  1 himanshu himanshu 0 Aug 31 16:58 cwd -> /home/himanshu/Desktop/MT2024059
-r--------  1 himanshu himanshu 0 Aug 31 16:58 environ
lrwxrwxrwx  1 himanshu himanshu 0 Aug 31 16:58 exe -> /home/himanshu/Desktop/MT2024059/a.out
dr-x------  2 himanshu himanshu 3 Aug 31 16:58 fd
dr-xr-xr-x  2 himanshu himanshu 0 Aug 31 16:58 fdinfo
-rw-r--r--  1 himanshu himanshu 0 Aug 31 16:58 gid_map
-r--------  1 himanshu himanshu 0 Aug 31 16:58 io
-r--------  1 himanshu himanshu 0 Aug 31 16:58 ksm_merging_pages
-r--------  1 himanshu himanshu 0 Aug 31 16:58 ksm_stat
-r--r--r--  1 himanshu himanshu 0 Aug 31 16:58 limits
-rw-r--r--  1 himanshu himanshu 0 Aug 31 16:58 loginuid
dr-x------  2 himanshu himanshu 0 Aug 31 16:58 map_files
-r--r--r--  1 himanshu himanshu 0 Aug 31 16:58 maps
-rw-------  1 himanshu himanshu 0 Aug 31 16:58 mem
-r--r--r--  1 himanshu himanshu 0 Aug 31 16:58 mountinfo
-r--r--r--  1 himanshu himanshu 0 Aug 31 16:58 mounts
-r--------  1 himanshu himanshu 0 Aug 31 16:58 mountstats
dr-xr-xr-x 59 himanshu himanshu 0 Aug 31 16:58 net
dr-x--x--x  2 himanshu himanshu 0 Aug 31 16:58 ns
-r--r--r--  1 himanshu himanshu 0 Aug 31 16:58 numa_maps
-rw-r--r--  1 himanshu himanshu 0 Aug 31 16:58 oom_adj
-r--r--r--  1 himanshu himanshu 0 Aug 31 16:58 oom_score
-rw-r--r--  1 himanshu himanshu 0 Aug 31 16:58 oom_score_adj
-r--------  1 himanshu himanshu 0 Aug 31 16:58 pagemap
-r--------  1 himanshu himanshu 0 Aug 31 16:58 patch_state
-r--------  1 himanshu himanshu 0 Aug 31 16:58 personality
-rw-r--r--  1 himanshu himanshu 0 Aug 31 16:58 projid_map
lrwxrwxrwx  1 himanshu himanshu 0 Aug 31 16:58 root -> /
-rw-r--r--  1 himanshu himanshu 0 Aug 31 16:58 sched
-r--r--r--  1 himanshu himanshu 0 Aug 31 16:58 schedstat
-r--r--r--  1 himanshu himanshu 0 Aug 31 16:58 sessionid
-rw-r--r--  1 himanshu himanshu 0 Aug 31 16:58 setgroups
-r--r--r--  1 himanshu himanshu 0 Aug 31 16:58 smaps
-r--r--r--  1 himanshu himanshu 0 Aug 31 16:58 smaps_rollup
-r--------  1 himanshu himanshu 0 Aug 31 16:58 stack
-r--r--r--  1 himanshu himanshu 0 Aug 31 16:58 stat
-r--r--r--  1 himanshu himanshu 0 Aug 31 16:58 statm
-r--r--r--  1 himanshu himanshu 0 Aug 31 16:58 status
-r--------  1 himanshu himanshu 0 Aug 31 16:58 syscall
dr-xr-xr-x  3 himanshu himanshu 0 Aug 31 16:58 task
-rw-r--r--  1 himanshu himanshu 0 Aug 31 16:58 timens_offsets
-r--r--r--  1 himanshu himanshu 0 Aug 31 16:58 timers
-rw-rw-rw-  1 himanshu himanshu 0 Aug 31 16:58 timerslack_ns
-rw-r--r--  1 himanshu himanshu 0 Aug 31 16:58 uid_map
-r--r--r--  1 himanshu himanshu 0 Aug 31 16:58 wchan

*/
