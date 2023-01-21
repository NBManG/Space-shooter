#ifndef BOSSFINAL_ENEMY_H
#define BOSSFINAL_ENEMY_H

#include "enemy.h"
/*this header file is for the final boss,inheritance from the abs class enemy*/
class bossfinal_enemy : public enemy
{
public:
    bossfinal_enemy();
    virtual void HP_decrease(int damage);
    virtual spacecraft::category get_category() const;
    virtual spacecraft::Type get_type() const;
    virtual int get_hp() const;
    virtual int get_damage() const;
};

#endif // BOSSFINAL_ENEMY_H
