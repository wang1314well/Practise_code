#include <iostream>
#include "mydialog.h"
#include <QMessageBox>
using namespace std;

MyDialog::MyDialog(QWidget *parent)
{
	resize(400,300);
	btn=new QPushButton(this);
	btn->resize(100,30);
	btn->move(150,150);
	btn->setText("OK");

	connect(btn,SIGNAL(clicked()),this,SLOT(showbox()));
}

MyDialog::~MyDialog()
{
	delete btn;
}

void MyDialog::showbox()
{
//	cout<<"I'm clicked"<<endl;
	QMessageBox::information(this,"information","this is a click");
}
