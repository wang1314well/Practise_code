#include <iostream>
using namespace std;
int main()
{
	int a = 0;
	int b = 0;
	for(int i = 0;i < 5;i++)
	{
		a = a + 1;
	}
	for(int i = 0;i < 5 ;++i)
	{
		b = b +1;
	}
	cout<<"a = "<<a<<endl<<"b = "<<b<<endl;
	return 0;
}
