#include <stdio.h>
int main()
{
	int i=0;
	char *num[4]={"hello","world","something","anyting"};
	for(;i<4;i++)
		printf("%s\n",num[i]);
	return 0;
}
