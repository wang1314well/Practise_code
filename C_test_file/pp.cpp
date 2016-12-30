#include <iostream>
using namespace std;
int main()
{
	int *p= new int;
	*p=10;
	cout<<"*p= "<<*p<<endl;
	p=NULL;
	delete p;
}
