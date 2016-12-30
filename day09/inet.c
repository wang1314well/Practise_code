#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>

int main()
{
	in_addr_t nip =192<<24 |168 <<16 |0 <<8 |26;
	char *ip = "192.168.0.26";
	char cip[4] = {192,168,0,26};

	struct in_addr sip ={nip};
	int myip;
	printf("struct to string:  %s\n",inet_ntoa(sip));
	myip = inet_addr(ip);
	printf("string to int: %d\n",myip);
	printf("string to int: %u.%u.%u.%u\n",myip>>24&255,myip>>16&255,myip>>8&255,myip>>0&255);
	
	exit(0);
}
