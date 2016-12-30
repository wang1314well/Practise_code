#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main()
{
	int serverfd;
	int cfd;
	struct sockaddr_in sadr;
	struct sockaddr_in cadr;
	int r ;

	if((serverfd = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
		printf("socket error: %m\n");
		exit(-1);
	}
	printf("socket sucess!\n");

	sadr.sin_family = AF_INET;
	sadr.sin_port = htons(9999);
	inet_aton("192.168.119.128",&sadr.sin_addr);

	r = bind(serverfd,(struct sockaddr*)&sadr,sizeof(sadr));
	if(r == -1)
	{
		printf("bind error  :%m\n");
		exit(-1);
	}
	printf("bind sucess!\n");

	r = listen(serverfd,10);
	if(r == -1)
	{
		printf("listen error :%m\n");
		exit(-1);
	}
	printf("listen sucess!\n");
	
	socklen_t len;

		len = sizeof(cadr);
		cfd = accept(serverfd,(struct sockaddr*)&cadr,&len);
		printf("someone connect:%d,IP:%s:%u\n",cfd,inet_ntoa(cadr.sin_addr),ntohs(cadr.sin_port));
	
	char buf[1024];
	while(1)
	{
		r =recv(cfd,buf,1024,0);
		if(r > 0)
		{
			buf[r] = 0;
			printf("::%s\n",buf);
		}
		if(r==0)
		{
			printf("connect over!\n");
			break;
		}
		if(r== -1)
		{
			printf("internet error\n");
		}
	}
	return 0;
}
