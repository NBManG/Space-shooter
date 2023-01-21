#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include<QTimer>
#include<QPainter>
#include<QPalette>
#include<QMovie>
#include"widget.h"
/*this is for the initial menuwindow*/
namespace Ui {
class MenuWindow;
}
//menu of the game
class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();
    void start_game();
    void loop();
private:
    Ui::MenuWindow *ui;
    //pixmap in animation
    QPixmap *airplane;
    QPixmap *bullet;
    int airplanex,airplaney,bulletx[4],bullety[4];//coordinate, use in animation
    QTimer *animate;//timer for animation
    QPainter paint;
    QMovie *movie;//display a gif

private slots:
    void on_btn_start_clicked();
};

#endif // MENUWINDOW_H
