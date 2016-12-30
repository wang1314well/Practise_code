#ifndef TH_ACCEPT_H
#define TH_ACCEPT_H
#include <QThread>
#include "chatexception.h"
#include "serversocket.h"

class ThAccept : public QThread
{
Q_OBJECT
private:
	ServerSocket     server;
public:
	void init() throw(ChatException);
	void run();      

public: signals:
	void sigInfo(const QString &);
private:

};

#endif
