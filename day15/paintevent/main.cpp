#include <QApplication>
#include "paintwidget.h"

int main(int argc,char** argv)
{
	QApplication app(argc,argv);
	PaintWidget w;
	w.resize(400,400);
//	w.move()
	w.show();
	return app.exec();
}
