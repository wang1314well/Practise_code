#include <iostream>

using namespace std;

int main()
{
	char word;
	cout<<"input a char:"<<endl;
	cin>>word;
	if(word>='A'&&word<='Z')
		cout<<(char)(word+32)<<endl;
	if(word>='a'&& word<='z')
		cout<<(char)(word-32)<<endl;
	return 0;
}
