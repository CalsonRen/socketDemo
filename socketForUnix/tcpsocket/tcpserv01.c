# include "unp.h"

int main(int argc, char** argv)
{
	int listenfd, connfd;
	pid_t childpid;
	socklen_t chillen;
	struct sockaddr_in cliaddr, servaddr;
	
	listenfd = Socket(AF_INET, SOCK_STRAM, 0);
	
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.saddr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);

	Bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

	Listen(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

	for(; ;)
	{
		clilen = sizeof(cliaddr);
		connfd = Accept(listenfd, (struct sockaddr*)&cliaddr, &clilen);

		if((childpid = Fork()) == 0)
		{
			//child process
			Close(connfd);
			str_echo(connfd);
			exit(0);
		}
		Close(connfd);
	}
	return 0;
}
