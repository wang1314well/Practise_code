#include <stdio.h>
int main()
{
	char a=(char)176,b=(char)219;
	printf("%c%c%c%c%c\n",b,a,a,a,b);
	printf("%c%c%c%c%c\n",a,b,a,b,a);
	printf("%c%c%c%c%c\n",a,a,b,a,a);
	printf("%c%c%c%c%c\n",a,b,a,b,a);
	printf("%c%c%c%c%c\n",b,a,a,a,b);
	system("chcp 437");
	return 0;
}
