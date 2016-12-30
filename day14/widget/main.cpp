#include <QApplication>
#include <QWidget>

int main(int argc,char** argv)
{
	QApplication app(argc,argv);
	
	QWidget w;
/*	w.resize(QSize(400,400));
	w.move(QPoint((1366-400)/2,(768-400)/2));   */

	w.setGeometry((1366-400)/2,(768-400)/2,400,400);

	QCursor cur(Qt::PointingHandCursor);
	w.setCursor(cur);
	w.show();
	return app.exec();
}
