#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pcap/pcap.h>

int main()
{
	char 		errbuf[PCAP_ERRBUF_SIZE];
	pcap_if_t	*it;
	int r ;
	r= pcap_findalldevs(&it,errbuf);
	if(r== -1)
	{
		printf("%s\n",errbuf);
		exit(-1);
	}

	while(it)
	{
		printf(":%s\n",it->name);
		it=it->next;
	}
	exit(0);
}
