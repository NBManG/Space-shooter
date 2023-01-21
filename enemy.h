#ifndef ENEMY_H
#define ENEMY_H

#include <spacecraft.h>
/*this file is for abs class enemy,there will be different kinds of enemies
class inheritance from this class*/
class enemy : public spacecraft
{
public:
    explicit enemy();
};

#endif // ENEMY_H
