#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>

int main()
{
	struct hostent *ent;
	ent = gethostbyname("www.sina.com");
	printf("%hhu.%hhu.%hhu.%hhu\n",ent->h_addr[0],ent->h_addr[1],ent->h_addr[2],ent->h_addr[3]);
	exit(0);
}
