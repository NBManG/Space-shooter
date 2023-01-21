#ifndef BULLETS_H
#define BULLETS_H
#include <spacecraft.h>

#include <QPixmap>
#include <QRect>
/*this file is for bullets,all the spacecraft's bullets handle by this*/

class bullets
{
public:
    explicit bullets(bool,int,int,int);
    ~bullets() = default;


    int get_x() const;
    int get_y() const;
    int get_speed() const;
    int get_damage () const;
    void set_damage (int);
    void set_coor(int,int); // set coordinates of bullet
    void set_speed(int);
    void updatePosition ();//update bullets position
    QPixmap graph;
    bool self_bullets();//check whether it is player's bullets.
private:
    bool is_mine;//set to be true if it is fired by the main character
    int x;
    int y;
    int speed;
    int damage;

};

#endif // BULLETS_H
