#include "demowidget.h"
//#include <QWidget>
#include <QApplication>

int main(int argc,char** argv)
{
	QApplication app(argc,argv);
	
	DemoWidget w;
	w.resize(400,400);
	w.show();
	return app.exec();
}
