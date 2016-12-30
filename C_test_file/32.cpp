#include <iostream>
#include "stdio.h"
#include "string.h"

using namespace std;

int main()
{
	string USART_RX_BUF = "hello world and anything";
	char *m_argv[20];
	int len = 0;
	int  i;
	int count = 0;
	char *p =&(char*)USART_RX_BUF;

	while(*p != '\0')
	{
		if(*p == ' ')
		{
			p++;
			count++;
		}
	}
	printf("count = %d\n",count);
	p = &USART_RX_BUF;
	for(i=0;i<=count;i++)
	{	
		if(*p == ' ')
		{
			p++;
			count++;
			break;
		}
		for(;*p != ' ';p++)
		{
			*m_argv[i] =*p;
			*m_argv[i]++;
		}					
	}

	
	for(i=0;i<=count;i++)
	{
		printf("%s\n",m_argv[i]);
	}

	return 0;
}
