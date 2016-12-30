#include "demowidget.h"

DemoWidget::DemoWidget(QWidget *parent):QWidget(parent)
{
	btn=new DemoPushButton(this);
	btn->resize(300,300);
	btn->move(100,100);
}
