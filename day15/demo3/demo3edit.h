#ifndef DEMO3_EDIT_H
#define DEMO3_EDIT_H
#include <QLineEdit>
#include <QKeyEvent>

class Demo3Edit : public QLineEdit
{
private:
//	Demo3Edit *e;	
public:
	Demo3Edit(QWidget *p=NULL);
protected:
	virtual void keyPressEvent(QKeyEvent *e);
};

#endif
