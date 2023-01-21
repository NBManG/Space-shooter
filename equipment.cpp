#include "equipment.h"
#include<cstdlib>
#include<time.h>
//initialize
equipment::equipment(int x, int y)
{
    this->x=x;
    this->y=y;
    graph =QPixmap("://pic/dice.png");//the graph to be displayed
    graph=graph.scaled(50,50,Qt::KeepAspectRatioByExpanding);
    //set category and type randomly
    srand((unsigned)time(NULL));
    int temp=rand()%3;
    if(temp==0)category=equipment::Category::damage;
    else if(temp==1)category=equipment::Category::hp;
    else category=equipment::Category::weapon;
    srand((unsigned)time(NULL));
    temp=rand()%3;
    if(temp==0)type=equipment::Type::small;
    else if(temp==1)type=equipment::Type::mid;
    else type=equipment::Type::large;
    temp=rand()%3;
    blt_type=temp;//set bullet type randomly
}
int equipment::get_x() const{
    return x;
}
int equipment::get_y() const{
    return y;
}
//category of equipment
equipment::Category equipment::get_category() const{
    return category;
}
//type of the equipment
equipment::Type equipment::get_type()const{
    return type;
}
//bullet type to be changed
int equipment::get_blt_type() const{
    return blt_type;
}
//damage increase
int equipment::get_damage_increase() const{
    return damage_increase[static_cast<int>(type)-1];
}
//hp increase
int equipment::get_hp_increase() const{
    return hp_increase[static_cast<int>(type)-1];
}

//update coordinate
void equipment::update_coord(){
    this->y+=3;
}
