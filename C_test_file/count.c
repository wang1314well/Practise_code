#include <stdio.h>
int f(int x,int y)
{
	return (x&y)+((x^y)>>1);
}
int main()
{
	printf("%d\n",f(729,271));
	return 0;
}
