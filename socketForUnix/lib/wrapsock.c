#include "unp.h"

int Accept(int fd, struct sockaddr* sa, socklen_t *salenptr)
{
again:
	int n;
	if((n == accept(fd, sa, salenptr)) < 0)
	{
	#ifdef EPROTO
		if(errno == EPROTO || errno == ECONNABORTED)
	#else
		if(errno == ECONNABORTED)
			goto again;
			else
				err_sys("accept error");
}
	return n; 
}

void Bind(int fd, const struct sockaddr* sa, socklen_t salen)
{
	if(bind(fd, sa, salen) < 0)
		err_sys("bind error");
}

void Connect(int fd, const struct sockaddr* sa, socklen_t salen)
{
	if(connect(fd, sa, salen) < 0)
		err_sys("connect error");
}

void Listen(int fd, int backlog)
{
	char *ptr;
	if((ptr = getenv("LISTENQ") != NULL))
	backlog = atoi(ptr);
	if(listen(fd, backlog) < 0)
		err_sys("listen error");
}

int Socket(int family, int type, int protocal)
{
	int n;
	if((n = socket(family, type, protocal)) < 0)
		err_sys("socket error")
	return n;
}
