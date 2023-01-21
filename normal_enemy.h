#ifndef NORMAL_ENEMY_H
#define NORMAL_ENEMY_H

#include <enemy.h>
/*this header file is for normal enemies,inheritance from the abs class enemy*/
class normal_enemy : public enemy
{
public:
    explicit normal_enemy();
    virtual void HP_decrease(int damage);
    virtual spacecraft::category get_category() const;
    virtual spacecraft::Type get_type() const;
    virtual int get_hp() const;
    virtual int get_damage() const;

};

#endif // NORMAL_ENEMY_H
