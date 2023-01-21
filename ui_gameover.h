/********************************************************************************
** Form generated from reading UI file 'gameover.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_H
#define UI_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameOver
{
public:
    QLabel *over;
    QLabel *Score_char;
    QLabel *Score_int;
    QPushButton *Restart;
    QLabel *Background;
    QPushButton *Exit;

    void setupUi(QWidget *GameOver)
    {
        if (GameOver->objectName().isEmpty())
            GameOver->setObjectName(QString::fromUtf8("GameOver"));
        GameOver->resize(820, 646);
        over = new QLabel(GameOver);
        over->setObjectName(QString::fromUtf8("over"));
        over->setGeometry(QRect(120, 100, 621, 181));
        Score_char = new QLabel(GameOver);
        Score_char->setObjectName(QString::fromUtf8("Score_char"));
        Score_char->setGeometry(QRect(110, 340, 191, 91));
        Score_int = new QLabel(GameOver);
        Score_int->setObjectName(QString::fromUtf8("Score_int"));
        Score_int->setGeometry(QRect(380, 340, 441, 91));
        Restart = new QPushButton(GameOver);
        Restart->setObjectName(QString::fromUtf8("Restart"));
        Restart->setGeometry(QRect(230, 490, 301, 81));
        Background = new QLabel(GameOver);
        Background->setObjectName(QString::fromUtf8("Background"));
        Background->setGeometry(QRect(0, -10, 821, 881));
        Exit = new QPushButton(GameOver);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        Exit->setGeometry(QRect(300, 600, 161, 61));
        Background->raise();
        Exit->raise();
        Restart->raise();
        over->raise();
        Score_char->raise();
        Score_int->raise();

        retranslateUi(GameOver);

        QMetaObject::connectSlotsByName(GameOver);
    } // setupUi

    void retranslateUi(QWidget *GameOver)
    {
        GameOver->setWindowTitle(QApplication::translate("GameOver", "Form", nullptr));
        over->setText(QApplication::translate("GameOver", "TextLabel", nullptr));
        Score_char->setText(QApplication::translate("GameOver", "TextLabel", nullptr));
        Score_int->setText(QApplication::translate("GameOver", "TextLabel", nullptr));
        Restart->setText(QApplication::translate("GameOver", "PushButton", nullptr));
        Background->setText(QApplication::translate("GameOver", "TextLabel", nullptr));
        Exit->setText(QApplication::translate("GameOver", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameOver: public Ui_GameOver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
