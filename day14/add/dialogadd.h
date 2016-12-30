#ifndef DLG_ADD_H
#define DLG_ADD_H
#include "add.h"
#include <QDialog>

class DlgAdd:public QDialog
{
Q_OBJECT
private:
	Ui_DlgAddUI  *ui;
public:
	DlgAdd(QWidget *parent=NULL);
	~DlgAdd();
public slots:
	void add();
};
#endif
