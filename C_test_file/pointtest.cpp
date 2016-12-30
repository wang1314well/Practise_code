#include <iostream>
using namespace std;
int main()
{
	float a = 3.14;
	float *p = &a;
	cout<<"p= "<<p<<endl<<"*p= "<<*p<<endl;
	return 0;
}
