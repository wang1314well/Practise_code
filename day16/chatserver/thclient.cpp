#include "thclient.h"
#include <sys/socket.h>
#include <list>
#include "serverwindow.h"
#include <unistd.h>

void ThClient::run()
{
	int r;
	char buf[1024];
	while(true)
	{
		r=recv(fd,buf,sizeof(buf)-1,0);
		if(r<=0)
		{
			emit sigInfo("someone exit");
			ServerWindow::allusers.remove(this);
			close(fd);
//			delete this;
			break;
		}
		buf[r] = 0 ;
		emit sigInfo(buf);
		list<ThClient*>::iterator it = ServerWindow::allusers.begin();
		while(it!=ServerWindow::allusers.end())
		{
			send((*it)->fd,buf,strlen(buf),0);
			it++;
		}
	}
}
