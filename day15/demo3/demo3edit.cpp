#include "demo3edit.h"
#include <cstdio>

using namespace std;

Demo3Edit::Demo3Edit(QWidget *p):QLineEdit(p)
{
//	printf();
}

void Demo3Edit::keyPressEvent(QKeyEvent *e)
{
	int key = e->key();
	if(key >=65 &&key<=90 ) // ||Key==Qt::Key_Backspace)
	{
		QLineEdit::keyPressEvent(e);
	}
	else
	{
		this->setText(this->text()+"*");
	}
	
}
