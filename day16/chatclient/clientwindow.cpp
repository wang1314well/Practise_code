#include "clientwindow.h"

ClientWindow::ClientWindow(QWidget *p)
{
    center = new QWidget(this);
    info = new QTextEdit(center);
    msg= new QLineEdit(center);
    btnsend = new QPushButton(center);
    hlay = new QHBoxLayout(center);
    vlay = new QVBoxLayout(center);
    hlay->addWidget(info);
    hlay->addLayout(vlay);
    
    vlay->addWidget(msg);
    vlay->addWidget(btnsend);
    
    this->setCentralWidget(center);
    this->show();
}
