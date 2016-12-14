#include "unp.h"

pid_t Fork()
{
	pid_t pid;
	if((pid = fork()) == -1)
		err_sys("fork error");
	return pid;
}


void Close(int fd)
{
	if(close(fd) == -1)
		err_sys("close error");
}


int Open(const char* pathname, int offlag, mode_t mode)
{
	int fd;
	if((fd = open(pathname, offlag, mode)) == -1)
		err_sys("open error");
	return fd;
}
