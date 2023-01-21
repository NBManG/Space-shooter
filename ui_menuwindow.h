/********************************************************************************
** Form generated from reading UI file 'menuwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWINDOW_H
#define UI_MENUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btn_start;
    QLabel *label;
    QLabel *background;
    QLabel *airplane;
    QLabel *bullet1;
    QLabel *bullet2;
    QLabel *bullet3;
    QLabel *bullet4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MenuWindow)
    {
        if (MenuWindow->objectName().isEmpty())
            MenuWindow->setObjectName(QString::fromUtf8("MenuWindow"));
        MenuWindow->resize(831, 1088);
        centralwidget = new QWidget(MenuWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btn_start = new QPushButton(centralwidget);
        btn_start->setObjectName(QString::fromUtf8("btn_start"));
        btn_start->setGeometry(QRect(180, 650, 331, 101));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 120, 651, 301));
        background = new QLabel(centralwidget);
        background->setObjectName(QString::fromUtf8("background"));
        background->setGeometry(QRect(0, 0, 831, 1071));
        airplane = new QLabel(centralwidget);
        airplane->setObjectName(QString::fromUtf8("airplane"));
        airplane->setGeometry(QRect(270, 340, 221, 121));
        bullet1 = new QLabel(centralwidget);
        bullet1->setObjectName(QString::fromUtf8("bullet1"));
        bullet1->setGeometry(QRect(230, 470, 281, 151));
        bullet2 = new QLabel(centralwidget);
        bullet2->setObjectName(QString::fromUtf8("bullet2"));
        bullet2->setGeometry(QRect(230, 390, 261, 231));
        bullet3 = new QLabel(centralwidget);
        bullet3->setObjectName(QString::fromUtf8("bullet3"));
        bullet3->setGeometry(QRect(250, 250, 311, 361));
        bullet4 = new QLabel(centralwidget);
        bullet4->setObjectName(QString::fromUtf8("bullet4"));
        bullet4->setGeometry(QRect(230, 560, 301, 81));
        MenuWindow->setCentralWidget(centralwidget);
        background->raise();
        label->raise();
        btn_start->raise();
        airplane->raise();
        bullet1->raise();
        bullet2->raise();
        bullet3->raise();
        bullet4->raise();
        menubar = new QMenuBar(MenuWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 831, 26));
        MenuWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MenuWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MenuWindow->setStatusBar(statusbar);

        retranslateUi(MenuWindow);

        QMetaObject::connectSlotsByName(MenuWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MenuWindow)
    {
        MenuWindow->setWindowTitle(QApplication::translate("MenuWindow", "MainWindow", nullptr));
        btn_start->setText(QString());
        label->setText(QApplication::translate("MenuWindow", "War of Spacecraft", nullptr));
        background->setText(QApplication::translate("MenuWindow", "TextLabel", nullptr));
        airplane->setText(QApplication::translate("MenuWindow", "TextLabel", nullptr));
        bullet1->setText(QApplication::translate("MenuWindow", "TextLabel", nullptr));
        bullet2->setText(QApplication::translate("MenuWindow", "TextLabel", nullptr));
        bullet3->setText(QApplication::translate("MenuWindow", "TextLabel", nullptr));
        bullet4->setText(QApplication::translate("MenuWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuWindow: public Ui_MenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
