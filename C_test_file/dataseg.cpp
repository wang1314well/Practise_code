#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <list>
#include <string>

using namespace std;



class DATASEG
{
private:
	string ID;
	string name;
	string ph_num;
	string gender;
	string depart;
public:
	DATASEG();
	DATASEG add(DATASEG &data);
}

DATASEG::DATASEG add(DATASEG &data)
{
	DATASEG *p = (DATASEG)malloc(sizeof(DATASEG));
	p->ID = data.ID;
	p->name = data.name;
	p->ph_num = data.ph_num;
	p->gender = data.gender;
	p->depart = data.depart;
	return *p;
}

int main()
{
 	list<DATASEG> listone;
	list<DATASEG>::iterator itor;
//	itor = listone.begin();
	DATASEG mydata("34979","maxwell","0818","male","spring");
	listone.push_back(add(mydata.add()));
//	cout<<itor.ID<<itor.name<<endl;
	cout<<listone[0].name<<endl;


	return 0;
}

