#include <QApplication>
#include <QDiglog>
#include <QPushButton>
#include <QTextCodec>

int main(int args, char **argv)
{
	QApplication app(args,argv);
	QWidget win;

	QTextCodec *codec = QTextCodec::codecForName("gb2312");
	QTextCodec::setCodecForTr(codec);

	QDialog dlg;
	dlg.setVisible(true);

	QPushButton btn(&win);
	btn.resize(100,30);
	btn.move(10,10);
	btn.show();

	
	return app.exec();
}
