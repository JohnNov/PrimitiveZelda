#pragma once
#include <string>
#include "Character.h"

class Monster: public Character{

public:
    Monster();
    virtual void moveAround() =0;  //Pure virtual function.  Now Werewolfs and Vampires HAVE to override it.
    //I believe Monster is now an abstract class since we made moveAround a pure virtual function
//    virtual void getHealth() = 0;
    virtual int getHealth();
    virtual void setHealth(int health);
    virtual void death();
    virtual void setToken(char theToken);
    virtual void setLoot(int gold);
    virtual int getLoot();
protected:

    int _x;
    int _y;
};
