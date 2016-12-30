#include "add.h"
#include "dialogadd.h"
//#include <>
DlgAdd::DlgAdd(QWidget *parent)
{
	ui=new Ui_DlgAddUI;
	ui->setupUi(this);
	connect(ui->btnequel,SIGNAL(clicked()),this,SLOT(add()));
}
DlgAdd::~DlgAdd()
{
	delete ui;
}
void DlgAdd::add()
{
	QString strAdded = ui->txtadded->text();
	QString strAdd   = ui->txtadd->text();

	int ia= strAdded.toInt();
	int ib = strAdd.toInt();

	int ic = ia+ib;

	ui->lblresult->setText(QString::number(ic));
}
