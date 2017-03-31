#pragma once
#include <string>
#include "Character.h"
using namespace std;

class Player : public Character {

public:
    Player();
    char getToken();
    int health = 300;
    int attack = 50;
    int loot = 50;

    void receiveDamage(int monsterDamage);
   int getHealth();
   void setHealth(int damage);
   int deathStatus();
   int getAttack();
   void setLoot(int gold);
   int getLoot();


protected:
    int _x;
    int _y;
    char _token = '@';
    bool _isDead = false;
};
