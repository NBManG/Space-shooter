#ifndef BOSS_ENEMY_H
#define BOSS_ENEMY_H

#include <enemy.h>
/*this header file is for boss enemies,inheritance from the abs class enemy*/
class boss_enemy : public enemy
{
public:
    boss_enemy();
    virtual void HP_decrease(int damage);
    virtual spacecraft::category get_category() const;
    virtual spacecraft::Type get_type() const;
    virtual int get_hp() const;
    virtual int get_damage() const;

};

#endif // BOSS_ENEMY_H
