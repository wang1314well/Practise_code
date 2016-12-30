#include <QApplication>
#include "dialogadd.h"

int main(int argc,char** argv)
{
	QApplication app(argc,argv);
	
	DlgAdd dlg;
	dlg.show();

	return app.exec();
}
