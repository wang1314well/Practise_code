#include <iostream>

using namespace std;

int main()
{
	int a[6]={4,2,1,5,6,3};
	int i,j,key;
	for(i=1;i<6;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0 && key<a[j])
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
	for(int k=0;k<6;k++)
		cout<<a[k]<<" ";
	cout<<endl;
}
