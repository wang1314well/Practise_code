#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main()
{
	
	int sfd,ffd,cfd;
	char buf[128];
	int len;
	int r;
	struct sockaddr_in dr;
	char filename[100];

	if((sfd = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
		printf("socket error\n");
		exit(-1);
	}
	printf("socket sucessful!\n");
	
	dr.sin_family = AF_INET;
	dr.sin_port = htons(9988);
	dr.sin_addr.s_addr = inet_addr("192.168.119.128");
	if((r = bind(sfd,(struct sockaddr*)&dr,sizeof(dr))) < 0)
	{
		printf("bind error \n");
		close(sfd);
		exit(-1);
	}
	printf("bind address sucessful\n");

	r = listen(sfd,10);
	if(r == -1)
	{
		printf("listen error\n");
		close(sfd);
		exit(-1);
	}
	printf("listen sucessful\n");

	cfd = accept(sfd,0,0);
	if(cfd == -1)
	{
		printf("accept error\n");
		close(sfd);
		exit(-1);
	}
	printf("begin to accept file\n");

	r = recv(cfd,&len,sizeof(len),MSG_WAITALL);
	r = recv(cfd,filename,len,MSG_WAITALL);
	filename[len] = 0;
	
	printf("trans filename : %s\n",filename);
	ffd = open(filename,O_RDWR|O_CREAT|0666);
	while(1)
	{
		r = recv(cfd,&len,sizeof(len),MSG_WAITALL);
		if(len == 0)
			break;
		r = recv(cfd,buf,len,MSG_WAITALL);

		write(ffd,buf,len);
	}
	close(ffd);
	close(cfd);
	close(sfd);
	printf("recv file done\n");
	

	exit(0);
}
