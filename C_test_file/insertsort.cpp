#include <iostream>

using namespace std;

int main()
{
	int key,i,j;
	int arry[6]={5,2,4,6,1,3};
	for( j=1;j<6;j++)
	{
		key=arry[j];
		i=j-1;
		while(i>=0 && arry[i]>key)
		{
			arry[i+1]=arry[i];
			i=i-1;
		}
		arry[i+1]=key;
	}
	for(int k=0;k<6;k++)
		cout<<arry[k]<<" ";
	cout<<endl;
}
