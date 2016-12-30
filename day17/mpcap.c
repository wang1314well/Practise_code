#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap/pcap.h>
#include <linux/if_ether.h>
#include <linux/ip.h>
#include <unistd.h>

int main()
{
	char 	errbuf[PCAP_ERRBUF_SIZE];
	char	*dev;
	dev = pcap_lookupdev(errbuf);
	printf("%s\n",dev);
	
	exit(0);
}
