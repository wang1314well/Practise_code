#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

int main()
{
	int sfd;
	int ffd;
	int r;
	char buf[128];
	struct sockaddr_in dr;
	char filename[]="udpa.c";

	if((sfd = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
		printf("socket error\n");
		exit(-1);
	}
	printf("socket sucess!\n");

	dr.sin_family = AF_INET;
	dr.sin_port = htons(9988);
	inet_aton("192.168.119.128",&dr.sin_addr);
	if((r = connect(sfd,(struct sockaddr*)&dr,sizeof(dr)))< 0)
	{	
		printf("connect error\n");
		exit(-1);
	}
	printf("connect sucess!\n");

	if((ffd = open(filename,O_RDONLY)) < 0)
	{
		printf("open error\n");
		close(sfd);
		exit(-1);
	}
	printf("open sucess!\n");
	
	int len;
	len = strlen(filename);
	if((r = send(sfd,&len,sizeof(len),0)) < 0)
	{
		printf("send error\n");
//		close(fd);
		close(ffd);
		close(sfd);
		exit(-1);
	}
	r = send(sfd,filename,len,0);
	printf("send sucess\n");
	
	int s;
	while(1)
	{
		if((r = read(ffd,buf,128)) < 0)
		{
			printf("read error\n");
			break;
		}
		if(r==0)
			break;
		if(r > 0)
		{
			if((s = send(sfd,&r,sizeof(r),0)) < 0)
			{
				break;
			}
			if((send(sfd,buf,r,0)) < 0)
				break;
		}
	}
	r = 0;
	s = send(sfd,&r,sizeof(r),0);
	close(ffd);
	close(sfd);
	printf("OK!\n");
	exit(0);


}
