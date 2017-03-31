#pragma once
#include <string>

class Character{

public:
    Character();

   virtual char getToken();
   virtual int getHealth()=0;
    void setHealth(int damage);
    void setLocation(int x, int y);
    void getLocation(int &x, int &y);
    int getAttack();
   virtual int deathStatus();
    virtual void setLoot(int gold);
    virtual int getLoot();
   int loot;


protected:
    int _x;
    int _y;
    int attack =10;
};

