#pragma GCC diagnostic error "-std=c++11"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string arr[]= {"hello","world","and"," hello"," everything"};
	vector<string> arr1(arr,arr+5);
	vector<string> arr2=arr1;
	vector<int>  arr3(10);
	vector<string>  arr4(arr1);
	vector<int>  arr5(10,10);
	vector<string> arr6(10,"hello");

	
	cout<<"arr1:"<<endl;
	for(int i=0;i<arr1.size();i++)
	{
		cout<<arr1[i]<<"  ";
	}
	cout<<endl;

	cout<<"arr2:"<<endl;
	for(int i=0;i<arr2.size();i++)
	{
	      cout<<arr2[i]<<"  ";
	}
	cout<<endl;

	cout<<"arr3:"<<endl;
	for(int i=0;i<arr3.size();i++)
	{
	      cout<<arr3[i]<<"  ";
	}
	cout<<endl;

	cout<<"arr4:"<<endl;
	for(int i=0;i<arr4.size();i++)
	{
	      cout<<arr4[i]<<"  ";
	}
	cout<<endl;

	cout<<"arr5:"<<endl;
	for(int i=0;i<arr5.size();i++)
	{
	      cout<<arr5[i]<<"  ";
	}
	cout<<endl;

	cout<<"arr6:"<<endl;
	for(int i=0;i<arr6.size();i++)
	{
	      cout<<arr6[i]<<"  ";
	}
	cout<<endl;


	return 0;
}
