#include <stdio.h>
//#include <conio.h>
int main()
{
	int arr[2][3] = {10,20,30,40,50,60};
	int k;
	for(k=0;k<2;k++)
	{
		printf("arr[%d] = %p  %d\n",k,arr[k],*arr[k]);
	}
	return 0;
}
