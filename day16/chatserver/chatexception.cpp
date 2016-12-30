#include "chatexception.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

ChatException::ChatException()
{
	memset(msg,0,sizeof(msg));
	sprintf(msg,"Char error!");
}

ChatException::ChatException(const char *m)
{
	memset(msg,0,sizeof(msg));
	sprintf(msg,"Chat error:%s!",m);
}

const char* ChatException::what()const throw()
{
	return msg;
}
