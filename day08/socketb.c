#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/un.h>

int main()
{
	int fd;
	if((fd = socket(AF_UNIX,SOCK_DGRAM,0)) <0)
	{
		printf("socket error :%m\n");
		exit(-1);
	}

//	printf("%d : %d \n",getpid(),fd);
	struct sockaddr_un addr = {0};
	addr.sun_family = AF_UNIX;
	memcpy(addr.sun_path,"my.sock",strlen("my.sock"));
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
