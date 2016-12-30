#ifndef CLIENT_WINDOW_H
#define CLIENT_WINDOW_H
#include <QMainWindow>
#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class ClientWindow:public QMainWindow
{
private:
    QWidget     *center;
    QTextEdit   *info;
    QLineEdit   *msg;
    QPushButton *btnsend;
    QHBoxLayout *hlay;
    QVBoxLayout *vlay;
public:
    ClientWindow(QWidget *p = NULL);
};

#endif