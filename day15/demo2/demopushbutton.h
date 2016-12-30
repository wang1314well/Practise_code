#ifndef DEMO_PUSHBUTTON_H
#define DEMO_PUSHBUTTON_H
#include <QPushButton>
#include <QPaintEvent>

class DemoPushButton : public QPushButton
{
public:
	DemoPushButton(QWidget *parent =NULL);
protected:
	virtual void paintEvent(QPaintEvent *e);
private:
	bool israised;
};

#endif
