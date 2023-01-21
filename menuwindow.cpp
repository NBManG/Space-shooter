#include "menuwindow.h"
#include "ui_menuwindow.h"
#include <QPainter>
#include<cstdlib>
#include<time.h>
#include<QIcon>
#include<QPalette>
MenuWindow::MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow)
{
    this->setFixedSize(800,800);
    this->setWindowTitle("War of Spacecraft");
    ui->setupUi(this);
    //an animation would be displayed before the start menu button is shown
    airplane=new QPixmap("://pic/hero.png");//the airplane pixmap shown in animation
    //a background gif is shown
    movie=new QMovie("://pic/menu_background.gif");
    movie->setScaledSize(QSize().scaled(800,800,Qt::KeepAspectRatio));
    movie->start();
    ui->background->setMovie(movie);
    ui->background->setScaledContents(true);//background gif
    ui->background->setVisible(true);
    ui->airplane->setVisible(false);//hide pixmap first
    ui->airplane->setPixmap(*airplane);
    //the bullet shown in the animation
    bullet=new QPixmap[4]{
    {"://pic/hero_bullet_7.png"}, {"://pic/hero_bullet_7.png"},{"://pic/hero_bullet_7.png"},{"://pic/hero_bullet_7.png"}};
    //hide the bullets first
    ui->bullet1->setVisible(false);
    ui->bullet1->setPixmap(bullet[0]);
    ui->bullet2->setPixmap(bullet[1]);//set qlabel to be pixmap
    ui->bullet2->setVisible(false);
    ui->bullet3->setVisible(false);
    ui->bullet3->setPixmap(bullet[2]);
    ui->bullet4->setVisible(false);
    ui->bullet4->setPixmap(bullet[2]);
    //the coordinate of airplane
    airplanex=350;
    airplaney=500;
    QPixmap logo("://pic/menu_logo.png");
    QPixmap start_btn("://pic/menu_start.png");
    ui->label->setPixmap(logo.scaled(569,103));//the logo of the game
    bulletx[0]=bulletx[1]=350;
    bulletx[2]=bulletx[3]=450;
    bullety[0]=bullety[2]=450;
    bullety[1]=bullety[3]=420;//coordinate of pixmap
    //setting the button
    ui->btn_start->setVisible(false);//hide the start button and logo first. Show them after animation
    ui->btn_start->setIcon(start_btn.scaled(150,70));
    ui->btn_start->setFlat(true);
    ui->btn_start->setStyleSheet("QPushButton { background-color: transparent;border: 3px }");
    ui->btn_start->setIconSize(QSize(150,70));
    ui->label->setVisible(false);
    setWindowIcon(QIcon("://pic/app.ico"));//set the icon of the window
    animate=new QTimer{this};
    connect(animate, &QTimer::timeout,this,&MenuWindow::loop);//starting animation
    animate->start(20);//display frame, 50 times per second



}
//delete the window
MenuWindow::~MenuWindow()
{
    delete ui;
    delete airplane;
    delete bullet;
}
//called if btn_start is clicked
void MenuWindow::start_game(){

    Widget *m=new Widget();//the main window
    m->setAttribute(Qt::WA_DeleteOnClose);
    m->show();
    close();//close current window
}
void MenuWindow::on_btn_start_clicked(){
    start_game();
}
//the animation of the menu
void MenuWindow::loop(){
    //display the airplane
    if(airplaney>=-100)ui->airplane->setVisible(true);
    else ui->airplane->setVisible(0);//hide when the animation is finished (the plane fly outside the screen)
    //display the bullet
    if(bullety[0]>=0)ui->bullet1->setVisible(true);
    else ui->bullet1->setVisible(false);//hide the bullets when they are outside the screen
    if(bullety[1]>=0)ui->bullet2->setVisible(true);
    else ui->bullet2->setVisible(false);
    if(bullety[2]>=0)ui->bullet3->setVisible(true);
    else ui->bullet3->setVisible(false);
    if(bullety[3]>=0)ui->bullet4->setVisible(true);
    else ui->bullet4->setVisible(false);
    ui->airplane->move(airplanex,airplaney);
    //move the bullet and the airplane
    ui->bullet1->move(bulletx[0],bullety[0]);
    ui->bullet2->move(bulletx[1],bullety[1]);
    ui->bullet3->move(bulletx[2],bullety[2]);
    ui->bullet4->move(bulletx[3],bullety[3]);
    if(bullety[0]<=0)airplaney-=10;
    for(int i=0;i<4;++i)bullety[i]-=15;
    //when animation finish, show the button and the logo
    if(airplaney<=-100){
        animate->stop();
        ui->btn_start->setVisible(true);
        ui->label->setVisible(true);
        movie->stop();
    }
}
