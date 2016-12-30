#include <stdio.h>
#include <netdb.h>

struct hostent *ent;

int main()
{
	sethostent(1);
	while(1)
	{
		ent = gethostent();
		if(ent == NULL)
			break;
		printf("hostname:%s\t",ent->h_name);
		printf("IP: %hhu.%hhu.%hhu.%hhu\n",ent->h_addr[0],ent->h_addr[1],ent->h_addr[2],ent->h_addr[3]);
	//	printf("other name:%s\n",h_aliases[0]);
	}
	endhostent();
}
