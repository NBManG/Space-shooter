#include "bullets.h"

bullets::bullets(bool mine,int x,int y,int type) : is_mine(mine),speed(2),damage(5)
{
    if(is_mine) //check whether it is player's bullet
    {
        //different bullet type
        switch (type) {

        case 0:
            this->graph.load("://pic/bullet_11.png");
            damage = 5;
            break;

        case 1:
            this->graph.load("://pic/2bullets.png");
            damage = 10;
            break;

        case 2:
            this->graph.load("://pic/3bullets.png");
            damage = 20;
            break;

        default:
            break;

        }

    }
    else //enemies bullet type
    {
        switch (type) {

        case 0:
            this->graph.load("://pic/bullet_1.png");
            break;

        case 1:
            this->graph.load("://pic/bullet_2.png");
            break;

        case 2:
            this->graph.load("://pic/bullet_4.png");
            this->graph.scaled(40,40,Qt::KeepAspectRatioByExpanding);
            break;

        case 3:
            this->graph.load("://pic/boss_blt.png");
            damage = 20;
            break;
        case 4:
            this->graph.load("://pic/R(1).png");
            damage= 30;
            break;
        case 5:
            this->graph.load("://pic/R(2).png");
            this->graph=this->graph.scaled(100,100,Qt::KeepAspectRatioByExpanding);
            damage=20;
            break;
        case 6:
            this->graph.load("://pic/bomb_supply.png");

            damage=30;
            break;
        default:
            break;

        }

    }

    set_coor(x,y);//initial its position

}

int bullets::get_x() const {
    return x;
}
int bullets::get_y() const{
    return y;
}
int bullets::get_speed() const {
    return speed;
}
int bullets::get_damage () const {
    return damage;
}
void bullets::set_damage (int dmg) {
    damage = dmg;
}
void bullets::set_coor(int x,int y){
    this->x = x;
    this->y = y;
} // set coordinates of bullet
void bullets::set_speed(int spd) {
    speed = spd;
}

void bullets::updatePosition () {
    if (is_mine) {
        y-=speed+1;

    }
    else {
        y+=speed+1;

    }


}
bool bullets::self_bullets()
{
    return is_mine;
}
