#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int r;
	int fd;
	struct sockaddr_in ad;
	char buf[100];
	socklen_t len;
	struct sockaddr_in ad_snd;
	if((fd = socket(AF_INET,SOCK_DGRAM,17)) < 0)
	{
		printf("socket error : %m\n");
		exit(-1);
	}
	ad.sin_family = AF_INET;
	ad.sin_port = htons(11111);
	inet_aton("192.168.119.128",&ad.sin_addr);
	if((r = bind(fd,(struct sockaddr*)&ad,sizeof(ad))) <0)
	{
		printf("bind error %m\n");
		exit(-1);
	}
	while(1)
	{
		if((r = recvfrom(fd,buf,sizeof(buf),0,(struct sockaddr*)&ad_snd,&len)) < 0)
		{
			printf("recv error %m\n");
			exit(-1);
		}
		buf[0];
		printf("send IP: %s,   data:%s\n",inet_ntoa(ad_snd.sin_addr),buf);
		if(r==0)
		{
			printf("close\n");
			close(fd);
			break;
		}
	}
	close(fd);
	exit(0);
}
