#include <QApplication>
#include "demo3widget.h"

int main(int argc,char** argv)
{
	QApplication app(argc,argv);
	Demo3Widget w;
	w.resize(400,400);
	w.show();
	return app.exec();
}
