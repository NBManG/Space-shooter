#include "main_char.h"

main_char::main_char()
{
    this->postion_x=500;
    this->postion_y=900;//intial player's postion
    this->self_HP=100;//intial player's HP,100 is max.
    this->graph.load("://pic/hero.png");
    this->graph=this->graph.scaled(100,100,Qt::KeepAspectRatioByExpanding);
    this->self_velocity=10;
    this->damage=15;
    this->blt_type = 0; //new
}
void main_char::HP_decrease(int damage)
{
    this->self_HP-=damage;
    return;
}
spacecraft::category main_char::get_category() const
{
    return spacecraft::category::main_char;
}
void main_char::HP_increase(int num){
    if(this->self_HP+num<=100)
    {
        this->self_HP+=num;
    }
    else
    {
        this->self_HP=100;
    }
    return;
}
int main_char::get_hp() const
{
    return this->self_HP;
}
int main_char::get_damage() const
{
    return this->damage;
}
spacecraft::Type main_char::get_type() const
{
    return spacecraft::Type::self;
}
void main_char::increase_damage(int damage){
    this->damage+=damage;
}
