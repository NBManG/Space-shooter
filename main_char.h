#ifndef MAIN_CHAR_H
#define MAIN_CHAR_H

#include "spacecraft.h"
/*this is for the player's spacecraft,inheritance from spacecraft class*/
//the main character of the game
class main_char : public spacecraft
{

public:
    explicit main_char();
    virtual void HP_decrease(int damage);
    virtual spacecraft::category get_category() const;
    void HP_increase(int num);
    virtual int get_hp() const;
    virtual int get_damage() const;
    virtual spacecraft::Type get_type() const;
    void increase_damage(int damage);
};

#endif // MAIN_CHAR_H
