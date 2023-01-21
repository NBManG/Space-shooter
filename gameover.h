#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QWidget>
#include"QPixmap"
/*this is for the gameover window,when the player die or win,this window will show*/
namespace Ui {
class GameOver;
}
//the window shown if game over
class GameOver : public QWidget
{
    Q_OBJECT

public:
    explicit GameOver(int score,QWidget *parent = nullptr);
    ~GameOver();
    void Restart();//restart the game
    void Exit();//quit the game
public slots:
    void on_Exit_clicked();
    void on_Restart_clicked();
private:
    Ui::GameOver *ui;
    QPixmap *background,*exit,*restart,*score_char,*over;//the picture of the ui
    int score;//score get in the game
};

#endif // GAMEOVER_H
