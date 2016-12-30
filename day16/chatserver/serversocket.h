#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H
#include <QObject>
#include "chatexception.h"

class ServerSocket:public QObject
{
public:
	char 	ip[30];
	short 	port;
	int		fd;
public:
	void initSocket() throw(ChatException);
	int accept() throw(ChatException);
protected:
};

#endif
