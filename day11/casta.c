#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int 	fd;
	int 	r;
	int 	opt = 1;
	struct sockaddr_in dr;
	dr.sin_family = AF_INET;
	dr.sin_port	  = htons(9999);
	dr.sin_addr.s_addr = inet_addr("192.168.119.255");

	if((fd = socket(AF_INET,SOCK_DGRAM,0)) < 0)
	{
		printf("socket error :%m\n");
		exit(-1);
	}

	setsockopt(fd,SOL_SOCKET,SO_BROADCAST,&opt,sizeof(opt));

/*	if((bind(fd,(struct sockaddr*)&dr,sizeof(dr))) < 0)
	{
		printf("bind error %m\n");
		exit(-1);
	}
*/
	sendto(fd,"hello",5,0,(struct sockaddr*)&dr,sizeof(dr));
	close(fd);
	exit(0);
	
}
