#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <netdb.h>

int main()
{
	int fd;
	struct sockaddr_in ad;
	char buf[102];
	int r;
	fd = socket(AF_INET,SOCK_DGRAM,17);
	ad.sin_family = AF_INET;
	ad.sin_addr.s_addr = inet_addr("192.168.119.128");
	ad.sin_port = htons(11111);

	while(1)
	{
		r= read(0,buf,sizeof(buf)-1);
		buf[r-1]=0;
		r = sendto(fd,buf,r+1,0,(struct sockaddr*)&ad,sizeof(ad));
		if(r==-1 )
			break;
	}
	close(fd);
	exit(0);
}
