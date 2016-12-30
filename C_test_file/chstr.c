#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void chstring(char *str)
{
	int i=0;
	int j=0;
	int count=0;
	char *p=str;
	char *m_str[50];
	for(;*p!=' ';p++)
	{
		*m_str=p;
		i++;
	}
	if(*p=' ')
	{
		count++;
		if(count==1)
			printf("command of %s :",str);
		else
			printf("data of %s:",str);
		p++;
		m_str[50]++;
		j++;
	}
	for(;i<=i;j++)
	{
		printf("%s",m_str[j]);
	}
	printf("\n");
	if(*p=='\r')
		exit(0);
}
int main()
{
	char string[128];
    if(	fgets(string,125,stream) == 0)
		printf("input success\n");
	chstring(string);
	return 0;
}
