#include "serversocket.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void ServerSocket::initSocket() throw(ChatException)
{
	if((fd = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
		throw ChatException("socket error");
	}
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port   = htons(port);
	addr.sin_addr.s_addr = inet_addr(ip);

	int r;
	if((r = bind(fd,(struct sockaddr*)&addr,sizeof(addr))) < 0)
	{
		close(fd);
		throw ChatException("bind error");
	}
		

	if((r = listen(fd,10))<0)
	{
		close(fd);
		throw ChatException("listen error");
	}
	
}

int ServerSocket::accept() throw(ChatException)
{
	int cfd;
	cfd = ::accept(fd,NULL,0);
	if(cfd == -1)
		throw ChatException("accept error");
	
	return cfd;
}
