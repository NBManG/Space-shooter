#include "bossfinal_enemy.h"

bossfinal_enemy::bossfinal_enemy()
{
    this->postion_x=0;
    this->postion_y=0;//initial position(0,0)
    this->self_HP=3000;
    this->graph.load("://pic/bossfinal.png");
    this->graph=this->graph.scaled(300,300,Qt::KeepAspectRatioByExpanding);
    this->self_velocity=4;
    this->damage=20;

    this->blt_type = 5;//its bullet type

}


void bossfinal_enemy::HP_decrease(int damage)
{
    this->self_HP-=damage;
    return;
}
spacecraft::category bossfinal_enemy::get_category() const
{
    return spacecraft::category::enemy;
}
spacecraft::Type bossfinal_enemy::get_type() const
{
    return spacecraft::Type::bossfinal_enemy;
}
int bossfinal_enemy::get_hp() const
{
    return this->self_HP;
}
int bossfinal_enemy::get_damage() const
{
    return this->damage;
}
