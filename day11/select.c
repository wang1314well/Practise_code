#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>

int main()
{
	char	buf[1024];
	int 	sfd;
	int		fdall[100];
//	int		idx;
	int 	r;
	struct	sockaddr_in 	dr;
	fd_set	fds;
	int 	maxfd;
	int 	i,j;
	int 	count;

	if((sfd = socket(AF_INET,SOCK_STREAM,6)) <0 )
	{
		printf("socket error :%m\n");
		exit(-1);
	}
	printf("socket OK\n");
	
	dr.sin_family = AF_INET;
	dr.sin_port = htons(8866);
	inet_aton("192.168.119.128",&dr.sin_addr);
	
	if((r = bind(sfd,(struct sockaddr*)&dr,sizeof(dr))) <0)
	{
		printf("bind error :%m\n");
		close(sfd);
		exit(-1);
	}
	printf("bind OK\n");

	if((r = listen(sfd,10)) < 0)
	{
		printf("listen error:%m\n");
		close(sfd);
		exit(-1);
	}
	printf("listen OK\n");

	maxfd = 0;
	count = 0;
	FD_ZERO(&fds);
	for(i =0;i<100;i++ )
	{
		fdall[i] = -1;
	}
	
	while(1)
	{
		FD_ZERO(&fds);

		FD_SET(sfd,&fds);
		maxfd = maxfd>=sfd?maxfd:sfd;
		for(i = 0;i<count;i++)
		{
			if(fdall[i] != -1)
			{
				FD_SET(fdall[i],&fds);
				maxfd = maxfd>=fdall[i]?maxfd:fdall[i];
			}
		}

		r = select(maxfd+1,&fds,0,0,0);
		if(r==-1)
		{
			printf("servers broken \n");
			break;
		}

		if(FD_ISSET(sfd,&fds))
		{
			fdall[count] = accept(sfd,0,0);
			printf("someone connect \n");
			count++;
		}

		for(i =0;i<count;i++ )
		{
			if(fdall[i] != -1 && FD_ISSET(fdall[i],&fds))
			{
				recv(fdall[i],buf,1023,0);
				if(r == 0)
				{
					printf("someone getout !\n");
					close(fdall[i]);
					fdall[i] = -1;
				}
				if(r == -1)
				{
					printf("net work error \n");
					close(fdall[i]);
					fdall[i] = -1;
				}
				if(r> 0)
				{
					for(j = 0;j<count;j++)
					{
						if(fdall[j] != -1)
						{
							send(fdall[j],buf,r,0);
						}
					}
				}
			}
		}
	}

	exit(0);
}
