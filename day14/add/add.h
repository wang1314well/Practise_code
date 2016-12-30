/********************************************************************************
** Form generated from reading UI file 'add.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ADD_H
#define ADD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DlgAddUI
{
public:
    QFrame *frame;
    QLineEdit *txtadd;
    QLineEdit *txtadded;
    QLabel *label;
    QPushButton *btnequel;
    QLabel *lblresult;

    void setupUi(QDialog *DlgAddUI)
    {
        if (DlgAddUI->objectName().isEmpty())
            DlgAddUI->setObjectName(QString::fromUtf8("DlgAddUI"));
        DlgAddUI->resize(634, 147);
        frame = new QFrame(DlgAddUI);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 20, 571, 80));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        txtadd = new QLineEdit(frame);
        txtadd->setObjectName(QString::fromUtf8("txtadd"));
        txtadd->setGeometry(QRect(10, 30, 113, 23));
        txtadded = new QLineEdit(frame);
        txtadded->setObjectName(QString::fromUtf8("txtadded"));
        txtadded->setGeometry(QRect(159, 30, 113, 23));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(135, 30, 21, 21));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        btnequel = new QPushButton(frame);
        btnequel->setObjectName(QString::fromUtf8("btnequel"));
        btnequel->setGeometry(QRect(288, 26, 51, 31));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        btnequel->setFont(font1);
        lblresult = new QLabel(frame);
        lblresult->setObjectName(QString::fromUtf8("lblresult"));
        lblresult->setGeometry(QRect(360, 30, 131, 21));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        lblresult->setFont(font2);
        lblresult->setFrameShape(QFrame::Box);
        lblresult->setFrameShadow(QFrame::Sunken);

        retranslateUi(DlgAddUI);

        QMetaObject::connectSlotsByName(DlgAddUI);
    } // setupUi

    void retranslateUi(QDialog *DlgAddUI)
    {
        DlgAddUI->setWindowTitle(QApplication::translate("DlgAddUI", "ADD", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DlgAddUI", "+", 0, QApplication::UnicodeUTF8));
        btnequel->setText(QApplication::translate("DlgAddUI", "=", 0, QApplication::UnicodeUTF8));
        lblresult->setText(QApplication::translate("DlgAddUI", "result", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgAddUI: public Ui_DlgAddUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ADD_H
