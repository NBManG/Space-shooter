#include "gameover.h"
#include "ui_gameover.h"
#include<QIcon>
#include"widget.h"
GameOver::GameOver(int score,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameOver),score(score)
{

    this->setFixedSize(800,800);//window size
    this->setWindowTitle("War of Spacecraft");//window title
    ui->setupUi(this);
    //set up QPixmap and qlabel
    exit=new QPixmap("://pic/over_exit.png");//exit button's picture
    ui->Exit->setIcon(exit->scaled(114,50));//set icon of exit button to the picture
    ui->Exit->setStyleSheet("QPushButton { background-color: transparent;border: 3px }");//hide the background of button, show the picture only
    ui->Exit->setFlat(true);
    ui->Exit->setIconSize(QSize(114,50));
    //same things done to restart button
    restart=new QPixmap("://pic/over_restart.png");
    ui->Restart->setIcon(restart->scaled(159,70));
    ui->Restart->setFlat(true);
    ui->Restart->setStyleSheet("QPushButton { background-color: transparent;border: 3px }");
    ui->Restart->setIconSize(QSize(159,70));
    //score
    score_char=new QPixmap("://pic/over_score.png");
    ui->Score_char->setPixmap(score_char->scaled(169,70));
    over=new QPixmap("://pic/over_over.png");
    ui->over->setPixmap(over->scaled(537,120));
    //the background picture
    background=new QPixmap("://pic/over_background.png");
    ui->Background->setPixmap(background->scaled(800,800));
    ui->Score_int->setText(QString::number(score));
    //set the font of score_int
    QFont f=ui->Score_int->font();
    f.setBold(true);
    f.setPointSize(72);
    ui->Score_int->setFont(f);
    ui->Score_int->setStyleSheet("QLabel{color:white}");
    setWindowIcon(QIcon("://pic/app.ico"));//set the icon
}
//restart game
void GameOver::Restart(){
        Widget *m=new Widget();
        m->setAttribute(Qt::WA_DeleteOnClose);
        m->show();
        close();
}
void GameOver::on_Restart_clicked(){
    Restart();
}
//quit the game
void GameOver::Exit(){
    close();
}
void GameOver::on_Exit_clicked(){
    Exit();
}
//delete the window
GameOver::~GameOver()
{
    delete exit;
    delete restart;
    delete background;
    delete score_char;
    delete over;
    delete ui;
}
