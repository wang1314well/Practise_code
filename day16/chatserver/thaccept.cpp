#include "thaccept.h"
#include <cstdio>
#include "thclient.h"
#include "serverwindow.h"
using namespace std;

void ThAccept::init() throw(ChatException)
{
	sprintf(server.ip,"%s","192.168.119.128");
	server.port = 8888;
	try
	{
		server.initSocket();
	}
	catch(ChatException e)
	{
		throw e;
	}
}

void ThAccept::run()
{
	while(true)
	{
		try
		{
			int fd = server.accept();
			emit sigInfo("someone connecting");
			ThClient *th = new ThClient ;
			th->fd = fd;
			ServerWindow::allusers.push_back(th);
			th->start();
		}
		catch(ChatException e)
		{
			emit sigInfo("Server broken!!!");
			break;
		}
	}
}

