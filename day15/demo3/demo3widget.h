#ifndef DEMO3_WIDGET_H
#define DEMO3_WIDGET_H
#include <QWidget>
#include "demo3edit.h"

class Demo3Widget:public QWidget
{
public:
	Demo3Widget(QWidget *parent =NULL);
private:
	Demo3Edit *edt;
protected:
//	virtual void keyPressEvent(QKeyEvent *e);
};

#endif
