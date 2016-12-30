#include <QApplication>
#include "mydialog.h"


int main(int argc,char **argv)
{
	QApplication app(argc,argv);
	MyDialog dlg;
	dlg.show();
//	connect(btn,SIGNAL(clicked()),this,SLOT(showbox()));
	return app.exec();
}
