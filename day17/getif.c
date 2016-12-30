#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <string.h>


int main()
{
	int fd;
	int count;
	int r;
	int i;
	fd = socket(AF_INET,SOCK_DGRAM,0);
	struct ifreq 	ir[10];
	struct ifconf   cf;
	cf.ifc_len = sizeof(ir);
	cf.ifc_req = ir;

	r= ioctl(fd,SIOCGIFCONF,&cf);

	count = cf.ifc_len/sizeof(struct ifreq);
	printf("IO count : %u\n",count);

	for(i = 0;i<count;i++)
	{
		struct ifreq re;
		struct sockaddr_in *ddr;
		printf("%s\n",ir[i].ifr_name);
		memcpy(re.ifr_name,ir[i].ifr_name,strlen(ir[i].ifr_name));
		r=ioctl(fd,SIOCGIFDSTADDR,&re);
		ddr = (struct sockaddr_in*)&re.ifr_dstaddr;
		printf("\t|-%s\n",inet_ntoa(ddr->sin_addr));
	}
	exit(0);
}
