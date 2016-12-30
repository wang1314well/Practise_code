#ifndef SERVER_WINDOW_H
#define SERVER_WINDOW_H
#include <QMainWindow>
#include <QWidget>
#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QStatusBar>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include "thaccept.h"
#include <QObject>
#include <list>
#include <thclient.h>
using namespace std;

class ServerWindow:public QMainWindow
{
Q_OBJECT
public:
	static list<ThClient*> allusers;
private:
	QTextEdit 	*info;
	QMenuBar	*bar;
	QMenu		*mnuserver;
	QAction		*actstart;
	QAction		*actexit;

	QStatusBar	*status;
	QLabel		*lbltip;
	QLabel		*lblresult;
	QLabel		*lbltime;

	ThAccept	thaccept;
public:
	ServerWindow(QWidget *p=NULL);
public slots:
	void onStart();
};

#endif
