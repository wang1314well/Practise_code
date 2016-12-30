#include <stdio.h>                                                          
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/mman.h>

int sfd;
int fds[100];
int idx = 0;
struct sockaddr_in dr;
int r;

int main()
{
//	int fd;
	fds = mmap(0,4*100,PROT_READ|PROT_WRITE,MAP_ANONYMOUS|MAP_SHARED,0,0);
	bzero(fds,sizeof(fds));
	if((sfd = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
		printf("socket error: %m\n");
		exit(-1);
	}
	printf("socket sucess!\n");
	dr.sin_family = AF_INET;
	dr.sin_family = htons(9989);
	dr.sin_addr.s_addr = inet_addr("192.168.119.128");
	r = bind(sfd,(struct sockaddr*)&dr,sizeof(dr));
	printf("bind sucess\n");

	listen(sfd,10);
	printf("listen sucess\n");
	while(1)
	{
		fds[idx] = accept(sfd,0,0);
		if(fds[idx] == -1)
			break;
		printf("someone connect \n");
		if(fork())
		{
			idx++;
			continue;
		}
		else
		{
			char buf[256];
			while(1)
			{
				r = recv(fds[idx],buf,255,0);
				if(r == 0)
				{
					printf("someone getout\n");
					close(fds[idx]);
					fds[idx] = 0;
					break;
				}
				if(r == -1)
				{
					printf("net error\n");
					close(fds[idx]);
					fds[idx] = 0;
					break;
				}
				int i;
				printf("data from client :%s",buf);
				for(i = 0;i < 100;i++)
				{
					if(fds[i]>0)
					{
						send(fds[i],buf,r,0);
					}
				}
			}
			exit(0);
		}
	}
	close(sfd);
	exit(0);
}

