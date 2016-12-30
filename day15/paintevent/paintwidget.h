#ifndef PAIT_WIDGET_H
#define PAIT_WIDGET_H
#include <QWidget>
#include <QPaintEvent>
#include <QTimer>

class PaintWidget:public QWidget
{
Q_OBJECT
private:
	int mouth;
	bool isopen;
	QTimer timer; 
protected:
	virtual void paintEvent(QPaintEvent *e);

public:
	PaintWidget();
public slots:
	void openMouth();
};

#endif
