#include "normal_enemy.h"
#include<cstdlib>
#include<time.h>
normal_enemy::normal_enemy()
{
    this->postion_x=0;
    this->postion_y=0;
    this->self_HP=10;
    srand((unsigned)time(NULL));
    int temp=rand()%4+1;//produce a random number inorder to choose different type pictures
    this->graph.load("://pic/img-plane_"+QString::number(temp)+".png");
    this->graph=this->graph.scaled(50,50,Qt::KeepAspectRatioByExpanding);
    this->self_velocity=2;
    this->damage=10;
    this->blt_type = rand()%3;//get random bullet type
}

void normal_enemy::HP_decrease(int damage)
{
    this->self_HP-=damage;
    return;
}

spacecraft::category normal_enemy::get_category() const
{
    return spacecraft::category::enemy;
}
spacecraft::Type normal_enemy::get_type() const
{
    return spacecraft::Type::normal_enemy;
}
int normal_enemy::get_hp() const
{
    return this->self_HP;
}
int normal_enemy::get_damage() const
{
    return this->damage;
}
