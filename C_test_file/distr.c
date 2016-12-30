#include <stdio.h>

char* chstring(char* m_string)
{
	char** q=NULL;
	char* p =m_string;
	if(p!=' ')	
	{
		*q=p;
		p++;
		*q++;
	}
	p++;
	else
		return *q;
}
int main()
{
	printf("")
	return 0;
}
