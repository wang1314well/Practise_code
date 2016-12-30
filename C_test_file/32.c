#include <stdio.h>
int main()
{
	char *USART_RX_BUF = "hello world and anything";
	char *m_argv[20];
	int len = 0;
	int  i=0;
	int count = 0;
	char *p;
	p = USART_RX_BUF;

	while(*p !='\0')
	{
		if(*p ==' ')
		{
			p++;
			count++;
		}
		p++;
	}

	p = USART_RX_BUF;
	if(i<=count)
	{
		while(*p !=' ')
		{

			**(m_argv+i) =*p;
			p++;
			*(m_argv+i)++;
		}

		p++;
		if(*p ==' ')
		{
			p++;
			**(m_argv+i) = '\0';
			i++;
		}
	}

	for(i=0;i<=count;i++)
	{
		printf("%s\n",m_argv[i]);
	}
	
//	printf("%s\n",m_argv);
	return 0;
}
