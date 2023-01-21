#include "boss1_enemy.h"
boss1_enemy::boss1_enemy()
{
    this->postion_x=0;
    this->postion_y=0;//initial position(0,0)
    this->self_HP=500;//boss1 enemy has HP 500.
    this->graph.load("://pic/boss1.png");
    this->graph=this->graph.scaled(250,250,Qt::KeepAspectRatioByExpanding);
    this->self_velocity=4;
    this->damage=30;
    this->blt_type = 4;//its bullet type
}

void boss1_enemy::HP_decrease(int damage)
{
    this->self_HP-=damage;
    return;
}
spacecraft::category boss1_enemy::get_category() const
{
    return spacecraft::category::enemy;
}
spacecraft::Type boss1_enemy::get_type() const
{
    return spacecraft::Type::boss1_enemy;
}
int boss1_enemy::get_hp() const
{
    return this->self_HP;
}
int boss1_enemy::get_damage() const
{
    return this->damage;
}
