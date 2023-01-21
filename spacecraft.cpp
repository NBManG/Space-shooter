#include "spacecraft.h"
#include<cstdlib>
#include<time.h>
spacecraft::spacecraft()
{

}
void spacecraft::set_it_position(int x, int y)
{
    //boss1 and final boss cannot move away from the screen
    if(this->get_type()==spacecraft::Type::boss1_enemy||this->get_type()==spacecraft::Type::bossfinal_enemy)
    {
        srand((unsigned)time(NULL));
        int temp=rand()%5-2;
        int x1=x+temp;
        if(x1<=200)
        {
            x1=200;
        }
        if(x1>=800)
        {
            x1=800;
        }
        postion_x=x1;
        postion_y=(y>=200)?200:y;
    }
    else
    {
        postion_x=x;
        postion_y=y;
    }

}
int spacecraft::get_x()const
{
    return postion_x;
}
int spacecraft::get_y()const
{
    return postion_y;
}
int spacecraft::get_velocity() const
{
    return self_velocity;
}
int spacecraft::get_score()
{
    if(this->get_type()==spacecraft::Type::boss_enemy)
    {
        return 100;
    }
    else if(this->get_type()==spacecraft::Type::normal_enemy)
    {
        return 30;
    }
    else if(this->get_type()==spacecraft::Type::boss1_enemy)
    {
        return 300;
    }
    else if(this->get_type()==spacecraft::Type::bossfinal_enemy)
    {
        return 1000;
    }
    else
    {
        return 0;
    }
}
void spacecraft::increase_damage(int damage){Q_UNUSED(damage);}
void spacecraft::HP_increase(int num){Q_UNUSED(num);}
