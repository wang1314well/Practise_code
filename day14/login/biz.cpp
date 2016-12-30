#include "biz.h"
#include <iostream>
#include <unistd.h>

using namespace std;

void Biz::biz()
{
	while(1)
	{
		sleep(1);
		cout<<"bussiness produce!"<<endl;
		emit siglog();
	}
}
