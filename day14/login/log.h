#ifndef		LOG_H
#define		LOG_H
#include <QObject>

class Log:public QObject
{
Q_OBJECT
public slots:
	void log();		
};

#endif
