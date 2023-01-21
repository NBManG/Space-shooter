#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include<QPixmap>
/*this file is for equipment class,there will be some different kinds of equipments in this game*/
class equipment
{
public:
    equipment(int x,int y);
    ~equipment()=default;
    QPixmap graph;
    //equipment can increase hp, damage, or change the weapon
    enum class Category{
        hp=1,
        damage=2,
        weapon=3
    };
    //for increase hp and damage only, indicate the number of hp and damage to increase
    enum class Type{
        small=1,
        mid=2,
        large=3
    };
    //accessor
    int get_x()const;
    int get_y()const;
    int get_hp_increase()const;
    int get_damage_increase()const;
    int get_blt_type()const;
    Category get_category()const;
    Type get_type()const;
    void update_coord();//update coordinate of equipment
private:
    equipment::Category category;
    equipment::Type type;
    int x,y,blt_type;//coordinate and bullet type to be changed
    //hp and damage increased for small, mid, and large
    int hp_increase[3]={10,20,30};
    int damage_increase[3]={5,10,15};
};

#endif // EQUIPMENT_H
