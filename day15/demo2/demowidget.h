#ifndef DEMO_WIDGET_H
#define DEMO_WIDGET_H
#include <QWidget>
#include "demopushbutton.h"

class DemoWidget : public QWidget
{
private:
	DemoPushButton *btn;
public:
	DemoWidget(QWidget *parent=NULL);
};

#endif
