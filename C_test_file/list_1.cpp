#include <iostream>
#include <list>
#include <numeric>
#include <algorithm>

using namespace std;

typedef list<char> LISTCH;

int main()
{
	LISTCH listch;
	LISTCH::iterator i;

	listch.push_front ('H');
	listch.push_front ('A');

	listch.push_back ('W');
	listch.push_back ('D');

	for(i=listch.begin();i !=listch.end();++i)
		cout<<*i<<"  ";
	cout<<endl;
}
