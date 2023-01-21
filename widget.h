#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include "spacecraft.h"
#include <QTimer>
#include <vector>
#include <QSound>
#include "equipment.h"
/*this is for the mainwidow,when the game starts,this window shows.
 all the game logic is in this class*/
class bullets;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void set_normal_enemy();//initial the normal enemies
    void set_boss_enemy();//initial the normal boss enemies
    void set_boss1_enemy();//initial the boss1 enemies
    void set_bossfinal_enemy();//initial the final boss enemies
    void paintEvent(QPaintEvent *);//function for draw pictures
    void keyReleaseEvent(QKeyEvent *event);//function for player's move
    void keyPressEvent(QKeyEvent *event);//function for player's move
    void move_self();//function for player's move
    bool check_collision_es(spacecraft*,spacecraft*);
    //check collision between enemies and player's spacecraft
    bool check_collision_ebs(bullets*,spacecraft*);
    //check collision between enemies'bullets and player's spacecraft
    bool check_collision_sbe(bullets*,spacecraft*);
    //check collision between enemies and player's spacecraft's bullets
    void main_loop();
    //the main loop for this game
    void all_update_positin();
    //update all spacecrafts,bullets,equipments position
    void bomb();
    //show bomb when bullets collision with spacecraft
    int get_distance(int,int,int,int);
    //return the distance between two points.
    void gameover();//called when game over
    void enemy_self_collision_check();
    //check collision between enemies and player's spacecraft
    bool self_bullet_check_with_allenemies(bullets*);
    //check collision between enemies and player's bullets.
    bool self_collide_equip();//detect if equipment collides with self_spacecraft
    void set_equip();//initialize equipment
    void add_buff();//add buff if collide with equipment
signals:
    void die();//sent if self's hp=0
private:
    QTimer* loop_timer;
    int score;
    QLabel* Score;
    QLabel* Hp;
    spacecraft* self_spacecraft{nullptr};//pointer to the player's spacecraft
    spacecraft* enemy_spacecraft[30]{nullptr};//array of pointers to the enemies
    int normal_enemy_showtime;//enemies initial time interval
    int boss_enemy_showtime;//boss enemies initial time interval
    int boss1_enemy_showtime;//boss1 enemies initial time interval
    int enemy_bullets_shoot_showtime;//enemies shoot  time interval
    int self_bullets_shoot_showtime;//player shoot time interval
    std::vector<bullets*> blts;//vector for all bullets
    QPixmap map1,map2;//picture of map
    int map1y,map2y;//y coordinate of map
    bool final_boss_exist;//indicate whether the final boss exist
    int bossfinal_index;//the index of final boss in the enemy_spacecraft array
    QPixmap* bombs[30]{}; //create 30 pixmap to draw the bomb picture when an enemy is dying.

    int bomb_index[30][3]{}; //a 2D-array storing the bomb step information of each enemy.
    bool UP;
    bool DOWN;
    bool LEFT;
    bool RIGHT;
    equipment *equip;//the equipment
};
#endif // WIDGET_H
