#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> arry(10);
	for(int i=0;i<arry.size();i++)
		arry[i]=i*i;
	for(int i=0;i<arry.size();i++)
		cout<<arry[i]<<"  ";
	cout<<endl;
	return 0;
}
