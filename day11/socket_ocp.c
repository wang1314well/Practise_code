#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>

int main()
{
	int 	fd;
	int 	type;
	int 	len;
	len = sizeof(type);

	fd = socket(AF_INET,SOCK_STREAM,0);

//	getsockopt(fd,SOL_SOCKET,SO_TYPE,&type,&len);
	getsockopt(fd,SOL_SOCKET,SO_RCVBUF,&type,&len);
	printf("%u\n",type);
	printf("%u:%u\n",SOCK_STREAM,type);
	if(type &SOCK_STREAM)
	{
		printf("stream\n");
	}

	if(type & SOCK_DGRAM)
	{
		printf("dgram\n");
	}
	exit(0);
}
