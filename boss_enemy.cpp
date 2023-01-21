
#include "boss_enemy.h"
#include<cstdlib>
#include<time.h>
boss_enemy::boss_enemy()
{
    this->postion_x=0;
    this->postion_y=0;//initial position(0,0)
    this->self_HP=100;
    srand((unsigned)time(NULL));
    int temp=rand()%3+5;//produce a random number inorder to choose different picture
    this->graph.load("://pic/img-plane_"+QString::number(temp)+".png");//randomly get a picqture
    this->graph=this->graph.scaled(150,150,Qt::KeepAspectRatioByExpanding);
    this->self_velocity=1;
    this->damage=30;
    this->blt_type = 3;//new
}
void boss_enemy::HP_decrease(int damage)
{
    this->self_HP-=damage;
    return;
}
spacecraft::category boss_enemy::get_category() const
{
    return spacecraft::category::enemy;
}
spacecraft::Type boss_enemy::get_type() const
{
    return spacecraft::Type::boss_enemy;
}
int boss_enemy::get_hp() const
{
    return this->self_HP;
}
int boss_enemy::get_damage() const
{
    return this->damage;
}
