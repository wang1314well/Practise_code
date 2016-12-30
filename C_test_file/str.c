#include <stdio.h>
int main(int argc,char *argv[])
{
	int i=1;
	printf("recevice command %s\n",argv[0]);
	for(i=1;i<argc;i++)
		printf("data%d of %s:%s\n",i,argv[0],argv[i]);
	return 0;
}
