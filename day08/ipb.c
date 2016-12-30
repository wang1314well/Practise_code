#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int fd;
	if((fd = socket(AF_INET,SOCK_DGRAM,0)) <0)
	{
		printf("socket error :%m\n");
		exit(-1);
	}

//	printf("%d : %d \n",getpid(),fd);
	struct sockaddr_in addr = {0};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9999);
	addr.sin_addr.s_addr = inet_addr("192.168.119.128");
//	memcpy(addr.sun_path,"my.sock",strlen("my.sock"));
	int r;
	if((r = connect(fd,(struct sockaddr*)&addr,sizeof(addr))) < 0)
	{
		printf("bind error :%m\n");
		exit(-1);
	}

	char buf[200];
	bzero(buf,sizeof(buf));
/*	if( (r =read(fd,buf,sizeof(buf))) < 0)
	{
		printf("read error\n");
	}   */
	write(fd,"helloc asdofgioad",17);
//	buf[r] = 0;
	close(fd);
	unlink("my.sock");
	exit(0);
}
