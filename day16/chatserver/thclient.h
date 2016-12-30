#ifndef TH_CLIENT_H
#define TH_CLIENT_H
#include <QThread>

class ThClient :public QThread
{
Q_OBJECT
public:
	int fd;
	void run();
public:signals:
	void sigInfo(const QString&);
};

#endif
