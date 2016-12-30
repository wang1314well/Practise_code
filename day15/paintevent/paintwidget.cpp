#include "paintwidget.h"
#include <QPainter>
#include <QImage>
#include <QPixmap>
//#include <QTimer>

void PaintWidget::openMouth()
{
	if(isopen)
	{
		mouth+=1;
		if(mouth>=30)
		{
			mouth=30;
			isopen=!isopen;
		}
	}
	else
	{
		mouth-=1;
		if(mouth<=0)
		{
			mouth=0;
			isopen=!isopen;
		}
	}
	repaint();
}

PaintWidget::PaintWidget():mouth(30),isopen(false)
{
	timer.setInterval(100);
	timer.start(100);
	connect(&timer,SIGNAL(timeout()),this,SLOT(openMouth()));
}

void PaintWidget::paintEvent(QPaintEvent *e)
{
	QPainter g(this);
	g.drawPie(100,100,100,100,mouth*16,(360-2*mouth)*16);
	



/*	QPoint p[3];
	p[0].setX(10);
	p[0].setY(10);
	p[1].setX(300);
	p[1].setY(300);
	p[2].setX(145);
	p[2].setY(200);
	QPainter g(this);
	g.drawLine(10,10,400,400);
	g.drawArc(10,10,300,300,10*16,120*16);
	g.drawChord(100,10,300,300,150*16,90*16);
	g.drawConvexPolygon(p,3);
	QImage img("OK.png");
	QPixmap("OK.png");
	QBitmap bit = map.createMaskFormColor(QColor(0,0,0,255));
	g.drawImage(10,10,img,0,0,100,100);
	g.drawEllipse(0,0,this->width(),this->height());
	g.drawPie(10,10,300,300,10*16,120*16);
	g.drawPixmap(10,10,300,300,bit);*/
}
