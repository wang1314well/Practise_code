#include "serverwindow.h"
#include <QColor>
#include <QMessageBox>
#include "chatexception.h"


list<ThClient*> ServerWindow::allusers;

void ServerWindow::onStart()
{
//	QMessageBox::information(this,"about","respond");
	
	try
	{	
		thaccept.init();
		info->setTextColor(QColor(0,255,0));
		info->append("Start sucessed");
		connect(&thaccept,SIGNAL(sigInfo(const QString&)),
		         info,SLOT(append(const QString&)));
		thaccept.start();
		info->append("servers receve thread start");

	}
	catch(ChatException e)
	{
		info->setTextColor(QColor(255,0,0));
		info->append(e.what());
	} 
}

ServerWindow::ServerWindow(QWidget *p)
{
	this->resize(1366,768);
	this->move(0,0); 
	this->setWindowTitle("Chat Servers");
	info = new QTextEdit;
	info->setTextColor(QColor(255,0,0));
	info->append("Welcome to use this soft");
	info->append("==========================\n");
	info->setTextColor(QColor(0,255,255));
	info->setFontPointSize(20);
//	info->insertPlainText("this is a talk");
//	info->clear();
	this->setCentralWidget(info);

	bar=new QMenuBar(this);
	mnuserver = new QMenu("start servers",bar);
	actstart  =	new QAction("Start",mnuserver);
	actexit	  = new QAction("Exit",mnuserver);

	mnuserver->addAction(actstart);
	mnuserver->addSeparator();
	mnuserver->addAction(actexit);
	bar->addMenu(mnuserver);
	this->setMenuBar(bar);

	status = new QStatusBar(this);
	lbltip  = new QLabel("About",status);
	lblresult = new QLabel("show result",status);
	lbltime = new QLabel("2016-11-16",status);

	status->addPermanentWidget(lbltip,300);
	status->addPermanentWidget(lblresult,500);
	status->addPermanentWidget(lbltime,0);

	this->setStatusBar(status);
	
	connect(actstart,SIGNAL(triggered()),this,SLOT(onStart()));

	this->show();
}
