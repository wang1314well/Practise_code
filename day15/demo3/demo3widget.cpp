#include "demo3widget.h"
#include "demo3edit.h"

Demo3Widget::Demo3Widget(QWidget *parent):QWidget(parent)
{
	edt=new Demo3Edit(this);
	edt->resize(200,30);
	edt->move(10,10);
}
