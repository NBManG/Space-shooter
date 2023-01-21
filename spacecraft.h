#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include <QPixmap>
/*This header file is a abstract class named spacecraft,all the enemies or
the player's spacecraft are inheritance from this class*/
class bullets;
class spacecraft
{
public:
    spacecraft();
    virtual~spacecraft()=default;
    enum class category{
        main_char=1,
        enemy=2
    };//the category of spacecraft,one is for play's spacecraft,one is for enemies.
    enum class Type{
        normal_enemy=1,
        boss_enemy=2,
        self=3,
        boss1_enemy=4,
        bossfinal_enemy=5
    };//the different type for different enemies,"self" is for player's spacecraft.
    virtual void HP_increase(int num);//for increase spacecraft's HP.
    virtual void increase_damage(int damage);//for increase spacecraft's damage.
    virtual spacecraft::Type get_type() const = 0;//get the type of spacecraft.
    virtual void HP_decrease(int damage) = 0;//for decrease spacecraft's HP.
    virtual spacecraft::category get_category() const = 0;//get the category of spacecraft.
    virtual int get_hp() const =0;//get spacecraft's HP.
    void set_it_position(int x,int y);//change spacecraft's position.
    int get_x() const;//get x coordinate
    int get_y() const;//get y coordinate
    int get_velocity() const;//get velocity of spacecraft
    virtual int get_damage() const =0;//get damage of spacecraft
    QPixmap graph;//store the picture of spacecraft
    int get_score();//get the corresponding score.
    int blt_type;//store the spacecraft's bullet's type.
protected:
    int postion_x;
    int postion_y;
    int self_HP;
    int damage;
    int self_velocity;
private:

};

#endif // SPACECRAFT_H
