#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <linux/if_ether.h>
#include <netinet/in.h>

int main()
{
	int fd;
	int r;
	char buf[2000];
	struct ethhdr	*eh;
	fd=socket(AF_PACKET,SOCK_RAW,htons(ETH_P_ALL));

	while(1)
	{
		r= read(fd,buf,2000);
		eh= (struct ethhdr*)buf;
		printf("Data protocol:%x:%d\n",ntohs(eh->h_proto),eh->h_proto);
	}
	exit(0);
}
