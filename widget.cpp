#include "widget.h"
#include <qpainter.h>
#include <QString>
#include "main_char.h"
#include "normal_enemy.h"
#include "boss_enemy.h"
#include "boss1_enemy.h"
#include "bossfinal_enemy.h"
#include <QKeyEvent>
#include <QPainter>
#include <QtGlobal>
#include <QTime>
#include <algorithm>
#include "bullets.h"
#include <cmath>
#include<QIcon>
#include"gameover.h"
#include<cstdlib>
Widget::Widget(QWidget *parent)
    : QWidget(parent),score(0),normal_enemy_showtime(0),boss_enemy_showtime(0),boss1_enemy_showtime(0),enemy_bullets_shoot_showtime(0),self_bullets_shoot_showtime(0),final_boss_exist(false)
{
    setAttribute(Qt::WA_DeleteOnClose,true);
    this->setFixedSize(1200,1000);

    this->setAutoFillBackground(true);
    this->setWindowTitle("War of spacecraft");
    UP = DOWN = LEFT = RIGHT = false;

    //concat two map to make the background move
    map1=QPixmap("://pic/img_bg_level_2.jpg");
    map1=map1.scaled(QSize(1200,1800),Qt::KeepAspectRatioByExpanding);
    map2=QPixmap("://pic/img_bg_level_2.jpg");
    map2=map2.scaled(QSize(1200,1800),Qt::KeepAspectRatioByExpanding);
    map1y=1800;//the coordinate of background
    map2y=0;

    //set font of qlabel score and hp
    QFont f=QFont("Microsoft YaHei", 10, 75);
    f.setBold(true);
    f.setPixelSize(36);
    Score=new QLabel(this);
    Score->setFont(f);
    //call gameover if die (hp<=0)
    connect(this,&Widget::die,this,&Widget::gameover);
    Score->setStyleSheet("QLabel{background:transparent;color:red;}");
    Score->setGeometry(0,-80,300,200);
    Hp=new QLabel(this);
    setWindowIcon(QIcon("://pic/app.ico"));//set the icon of the window
    Hp->setFont(f);
    Hp->setStyleSheet("QLabel{background:transparent;color:red;}");
    Hp->setGeometry(1000,-80,200,200);

    //initialize equipment
    equip=nullptr;
    //start the backgroud music
    QSound::play("./music/bgm11.wav");

    //initialize player's spacecraft
    self_spacecraft=new main_char;
    // Run main loop
    loop_timer = new QTimer{this };
    connect(loop_timer, &QTimer::timeout, this, &Widget::main_loop);
    // 100 updates per second
    loop_timer->start(10);
    srand(QTime(0,0,0).secsTo(QTime::currentTime()));


}

Widget::~Widget()
{
    //deallocate memory
    delete equip;
    equip=nullptr;
    loop_timer->stop();
    delete self_spacecraft;
    self_spacecraft=nullptr;
    for(int i=0;i<30;++i)
    {
        if(enemy_spacecraft[i]!=nullptr)
        {
            delete enemy_spacecraft[i];
            enemy_spacecraft[i]=nullptr;
        }
    }
    for(auto p=blts.begin();p!=blts.end();++p)
    {
        delete *p;
        *p=nullptr;
    }
}
void Widget::main_loop()//mian loop for this game
{
    //set the label of HP and Score
    Hp->setText("HP:"+QString::number(self_spacecraft->get_hp()));
    Score->setText("SCORE:"+QString::number(score));
    set_equip();//set a new equipment
    if(score>=3000)//when the player reaches 3000 score,the final boss appear
    {
        if(!final_boss_exist)//if no final boss,initialize it
        {
            set_bossfinal_enemy();
            final_boss_exist=true;//set the indicator to true
        }
        //when final boss's HP reach 1000,change its bullet type
        if(final_boss_exist&&(enemy_spacecraft[bossfinal_index]->get_hp()<=1000))
        {
            enemy_spacecraft[bossfinal_index]->blt_type=6;
        }

    }
    else//if the total score less than 3000
    {
        set_normal_enemy();//set new normal enemy
        set_boss_enemy();//set new boss enemy
        set_boss1_enemy();//set new boss1 enemy
    }

    all_update_positin();//update all spacecrafts,bullets,equipments'position
    enemy_self_collision_check();//check collison
    Hp->update();
    Hp->show();
    Score->update();
    Score->show();
    bomb();//show bomb picture
    move_self();//player's move
    update();
}


//update the bomb step of all dying enemies.
void Widget::bomb() {
    if (normal_enemy_showtime %2)
        return;
    for (int i=0;i<30 ;++i ) {
        if (bomb_index[i][0] == 8) {
            bomb_index[i][0] = 0;
            delete bombs[i];
            bombs[i] = nullptr;
        }
        if (bomb_index[i][0] != 0) {
            bombs[i]->load(QString::fromStdString("://pic/bomb-" + std::to_string(bomb_index[i][0]) + ".png"));
            ++bomb_index[i][0];

        }

    }
}
//initialize eequipment
void Widget::set_equip(){
    if(equip==nullptr&&rand()%10==1)equip=new equipment(rand()%1100+50,0);//set equip to random position
    //delete equipment if fly out of screen
    if(equip!=nullptr&&equip->get_y()>=1000){
        delete equip;
        equip=nullptr;
    }
}
void Widget::set_normal_enemy()
{

    ++normal_enemy_showtime;
    if(normal_enemy_showtime<=200)//handle normal enemy initial time interval
    {
        return;
    }
    normal_enemy_showtime=0;
    for(int i=0;i<30;++i)
    {
        if(enemy_spacecraft[i]==nullptr)
        {
            //initialize a new normal enemy and set its random position
            enemy_spacecraft[i]=new normal_enemy;
            enemy_spacecraft[i]->set_it_position(rand()%1100+50,0);
            break;
        }
    }
    return;
}
void Widget::set_boss_enemy()
{
    ++boss_enemy_showtime;
    if(boss_enemy_showtime<=1000)//handle boss enemy initial time interval
    {
        return;
    }
    boss_enemy_showtime=0;
    for(int i=0;i<30;++i)
    {
        if(enemy_spacecraft[i]==nullptr)
        {
            //initialize a new boss enemy and set its random position
            enemy_spacecraft[i]=new boss_enemy;
            enemy_spacecraft[i]->set_it_position(rand()%800+200,0);
            break;
        }
    }
    return;

}
void Widget::set_boss1_enemy()
{
    ++boss1_enemy_showtime;
    if(boss1_enemy_showtime<=5000)//handle boss1 enemy initial time interval
    {
        return;
    }
    boss1_enemy_showtime=0;
    for(int i=0;i<30;++i)
    {
        if(enemy_spacecraft[i]==nullptr)
        {
            //initialize a new boss1 enemy and set its random position
            enemy_spacecraft[i]=new boss1_enemy;
            enemy_spacecraft[i]->set_it_position(rand()%600+200,0);
            break;
        }
    }
    return;

}
void Widget::set_bossfinal_enemy()
{
    for(int i=0;i<30;++i)
    {
        if(enemy_spacecraft[i]==nullptr)
        {
            //initialize the final boss enemy and set its random position
            enemy_spacecraft[i]=new bossfinal_enemy;
            enemy_spacecraft[i]->set_it_position(rand()%600+200,0);
            bossfinal_index=i;//store the index
            break;
        }
    }
    return;
}
void Widget::all_update_positin()
{
    //update map's y coordinate
    map1y+=5;
    map2y+=5;
    if(map1y>=1800)map1y=-1780;
    if(map2y>=1800)map2y=-1780;

    //update coordinate of equipment
    if(equip!=nullptr)equip->update_coord();
    //change the main character if equipment collides the main character
    add_buff();

    //self_spacecraft shoot
    ++enemy_bullets_shoot_showtime;
    ++self_bullets_shoot_showtime;
    if(self_bullets_shoot_showtime>=50)//handle its shoot time interval
    {
        int change = 10+self_spacecraft->blt_type*10;//change the shoot position for different bullet type
        //new a bullet,set it into blts vector
        blts.push_back(new bullets(true,self_spacecraft->get_x()+self_spacecraft->graph.width()/2-change,self_spacecraft->get_y(),self_spacecraft->blt_type));//new
        self_bullets_shoot_showtime=0;
    }

    for(int i=0;i<30;++i)//update all enemies position
    {
        if(enemy_spacecraft[i]!=nullptr)
        {
            enemy_spacecraft[i]->set_it_position(enemy_spacecraft[i]->get_x(),enemy_spacecraft[i]->get_y()+enemy_spacecraft[i]->get_velocity());
            if(enemy_spacecraft[i]->get_y()>=1000)//delete the enemies move away from the screen
            {
                delete enemy_spacecraft[i];
                enemy_spacecraft[i]=nullptr;
                continue;
            }
        }
    }
    if(enemy_bullets_shoot_showtime>=50)//handle enemies shoot time interval
    {
        for(int i=0;i<30;++i)
        {
                if(enemy_spacecraft[i]!=nullptr)
                {
                    //different type of bullets show in different position
                    int x=0,y=0;
                    switch (enemy_spacecraft[i]->blt_type) {
                    case 0:case 1:case 2:
                        x = 8;
                        break;
                    case 3:
                        x = 18;
                        break;
                    case 4:
                        x = 18;
                        y = 50;
                        break;
                    case 5:
                        x = 25;
                        y = 50;
                        break;
                    default:
                        break;
                    }
                    blts.push_back(new bullets(false,enemy_spacecraft[i]->get_x()+enemy_spacecraft[i]->graph.width()/2-x,enemy_spacecraft[i]->get_y()+enemy_spacecraft[i]->graph.height()-y,enemy_spacecraft[i]->blt_type));


                }
        }
        enemy_bullets_shoot_showtime=0;
    }

    //bullets move
    for(auto p=blts.begin();p!=blts.end();)
    {
        if((*p)!=nullptr)
        {
            (*p)->updatePosition();
            if((*p)->get_y()<0||(*p)->get_y()>1000)//delete the bullets out of screen
            {

                auto p1=p;
                blts.erase(p1);

            }
            else
            {
                ++p;
            }
        }
        else
        {
            ++p;
        }
    }
    for(auto p=blts.begin();p!=blts.end();)//handle the player's bullets
    {
        if((*p)!=nullptr)
        {
            //delete the bullets collision with enemies
            if((*p)->self_bullets()&&self_bullet_check_with_allenemies((*p)))
            {
                auto p1=p;
                blts.erase(p1);

            }
            else
            {
                ++p;
            }
        }
        else
        {
            ++p;
        }
    }
    for(auto p=blts.begin();p!=blts.end();)//handle the enemies' bullets
    {
        if((*p)!=nullptr)
        {
            //delete the bullets collision with player's spacecraft
            if((!(*p)->self_bullets())&&check_collision_ebs(*p,self_spacecraft))
            {

                    if(self_spacecraft->get_hp()>0)//decrease the player's HP
                        self_spacecraft->HP_decrease((*p)->get_damage());

                    if(self_spacecraft->get_hp()<=0)//the player die
                    {

                        break;
                    }

                    auto p1=p;
                    blts.erase(p1);

            }
            else
            {
                    ++p;
            }
        }
        else
        {
            ++p;
        }
    }
    //check whether the game can continue
    if(self_spacecraft->get_hp()<=0||(final_boss_exist&&(enemy_spacecraft[bossfinal_index]==nullptr))){
        emit die();//emit signal if hp<=0
        loop_timer->stop();//stop the timer
    }
}
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform,true);
    //draw the map
    painter.drawPixmap(0,map1y,map1);
    painter.drawPixmap(0,map2y,map2);
    //draw equipment
    if(equip!=nullptr)painter.drawPixmap(equip->get_x(),equip->get_y(),equip->graph);
    painter.drawPixmap(self_spacecraft->get_x(),self_spacecraft->get_y(),self_spacecraft->graph);
    for(int i=0;i<30;++i)//draw all enemies
    {
        if(enemy_spacecraft[i]!=nullptr)
        {
            painter.drawPixmap(enemy_spacecraft[i]->get_x(),enemy_spacecraft[i]->get_y(),enemy_spacecraft[i]->graph);

        }
    }
    for(auto p=blts.begin();p!=blts.end();++p)//draw all bullets
    {
        painter.drawPixmap((*p)->get_x(),(*p)->get_y(),(*p)->graph);
    }
    //draw bomb pictures
    for (int i=0;i<30 ;++i ) {
        if (bombs[i]) {
            painter.drawPixmap(bomb_index[i][1],bomb_index[i][2],*bombs[i]);
        }
    }

}
void Widget::keyPressEvent(QKeyEvent *event)
{

    switch (event->key()) {
        case Qt::Key_W:case Qt::Key_Up:
            UP = true;
            break;
        case Qt::Key_S:case Qt::Key_Down:
            DOWN = true;
            break;
        case Qt::Key_A:case Qt::Key_Left:
            LEFT = true;
            break;
        case Qt::Key_D:case Qt::Key_Right:
            RIGHT = true;
            break;
        default:
            break;
        }

}
void Widget::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_W:case Qt::Key_Up:
            UP = false;
            break;
        case Qt::Key_S:case Qt::Key_Down:
            DOWN = false;
            break;
        case Qt::Key_A:case Qt::Key_Left:
            LEFT = false;
            break;
        case Qt::Key_D:case Qt::Key_Right:
            RIGHT = false;
            break;
        default:
            break;
        }

}
void Widget::move_self() {
    //the player only can move in the screen
    if (UP && self_spacecraft->get_y() > 0)
        self_spacecraft->set_it_position(self_spacecraft->get_x() ,self_spacecraft->get_y() - 5);//self_spacecraft->get_velocity()
    if (DOWN && self_spacecraft->get_y() < 900)
        self_spacecraft->set_it_position(self_spacecraft->get_x() ,self_spacecraft->get_y() + 5);
    if (LEFT && self_spacecraft->get_x() > 0)
        self_spacecraft->set_it_position(self_spacecraft->get_x() - 5,self_spacecraft->get_y());
    if (RIGHT && self_spacecraft->get_x() < 1050)
        self_spacecraft->set_it_position(self_spacecraft->get_x() + 5,self_spacecraft->get_y());

}
bool Widget::check_collision_es(spacecraft* enemy,spacecraft* self)
{

    //check collison
    if(get_distance(enemy->get_x()+enemy->graph.width()/2,enemy->get_y()+enemy->graph.height()/2,self->get_x()+self->graph.width()/2,self->get_y()+self->graph.height()/2)<=(enemy->graph.width()/2+self->graph.width()/2))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Widget::check_collision_ebs(bullets* enemy_bullets,spacecraft* self)
{
    //check collison
    if(get_distance(enemy_bullets->get_x()+enemy_bullets->graph.width()/2,enemy_bullets->get_y()+enemy_bullets->graph.height()/2,self->get_x()+self->graph.width()/2,self->get_y()+self->graph.height()/2)<=(enemy_bullets->graph.width()/2+self->graph.width()/2))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Widget::check_collision_sbe(bullets* self_bullets,spacecraft* enemy)
{
    //check collision
    if(get_distance(self_bullets->get_x()+self_bullets->graph.width()/2,self_bullets->get_y()+self_bullets->graph.height()/2,enemy->get_x()+enemy->graph.width()/2,enemy->get_y()+enemy->graph.height()/2)<=(self_bullets->graph.width()/2+enemy->graph.width()/2))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int Widget::get_distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
void Widget::gameover()
{
    GameOver *m=new GameOver(score);//show game over window
    m->setAttribute(Qt::WA_DeleteOnClose);
    m->show();
    close();
}
void Widget::enemy_self_collision_check()
{
    for(int i=0;i<30;++i)
    {
        if(enemy_spacecraft[i]!=nullptr)
        {
            if(check_collision_es(enemy_spacecraft[i],self_spacecraft))
            {
                //enemy's HP larger than player's
                if(enemy_spacecraft[i]->get_hp()>=self_spacecraft->get_hp())
                {
                    //decrease player's HP
                    self_spacecraft->HP_decrease(self_spacecraft->get_hp());
                    break;
                }
                else
                {
                    //decrease player's HP
                    self_spacecraft->HP_decrease(enemy_spacecraft[i]->get_hp());
                    //delete the enemy collision with player
                    delete enemy_spacecraft[i];
                    enemy_spacecraft[i]=nullptr;

                }
            }
        }

    }
}

bool Widget::self_bullet_check_with_allenemies(bullets* mine_bullet)
{
    for(int i=0;i<30;++i)
    {
        //collision exist
        if(enemy_spacecraft[i]!=nullptr&&check_collision_sbe(mine_bullet,enemy_spacecraft[i]))
        {
            //decrease enemy's HP
            enemy_spacecraft[i]->HP_decrease(self_spacecraft->get_damage()+mine_bullet->get_damage());
            if(enemy_spacecraft[i]->get_hp()<=0)//check whether enemy is die
            {
                score+=enemy_spacecraft[i]->get_score();//increase score

                bomb_index[i][0] = 1; //set the bomb step of ith enemy,1 means that the first picture of bomb should be shown.
                bomb_index[i][1] = enemy_spacecraft[i]->get_x();//pass the coordinates of this enemy to draw bomb picture.
                bomb_index[i][2] = enemy_spacecraft[i]->get_y();
                bombs[i] = new QPixmap;




                delete enemy_spacecraft[i];
                enemy_spacecraft[i]=nullptr;
            }
            return true;
        }
    }
    return false;//no collision
}
//check if the equipment collides with self_spacecraft
bool Widget::self_collide_equip(){
    if(equip==nullptr)return 0;//return false if equip is null
    //check distance between them
    return get_distance(equip->get_x()+equip->graph.width()/2,equip->get_y()+equip->graph.height()/2,self_spacecraft->get_x()+self_spacecraft->graph.width()/2,self_spacecraft->get_y()+self_spacecraft->graph.height()/2)<=(self_spacecraft->graph.width()/2+equip->graph.width()/2);
}
//add buff to self_spacecraft if colldide with equip
void Widget::add_buff(){
    if(self_collide_equip()){
        //ncrease hp
        if(static_cast<int>(equip->get_category())==1){
            self_spacecraft->HP_increase(equip->get_hp_increase());
        }
        //increase damage
        else if(static_cast<int>(equip->get_category())==2){
            self_spacecraft->increase_damage(equip->get_damage_increase());
        }
        //change weapon
        else self_spacecraft->blt_type=equip->get_blt_type();
        //delete the equipment after collision
        delete equip;
        equip=nullptr;
    }
}
