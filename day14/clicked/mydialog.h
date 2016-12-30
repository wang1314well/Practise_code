#ifndef MY_DIALOG_H
#define MY_DIALOG_H
#include <QDialog>
#include <QPushButton>

class MyDialog : public QDialog
{
Q_OBJECT
private:
	QPushButton		*btn;
public:
	MyDialog(QWidget *parent=NULL);
	~MyDialog();
public slots:
	void showbox();
};

#endif
