#include <stdio.h>
#include <netdb.h>

int main()
{
	struct protoent *ent;
	ent=getprotobyname("udp");
	printf("%d\n",ent->p_proto);
	return 0;
}
