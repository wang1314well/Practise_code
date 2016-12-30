#ifndef  BIZ_H
#define  BIZ_H
#include <QObject>

class Biz : public QObject
{
Q_OBJECT
public:
	void biz();
public:
	signals:
	void siglog();
};
#endif
