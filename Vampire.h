#pragma once
#include <string>
#include "Character.h"      //For inheritance/polymorphism
#include "Monster.h"


class Vampire: public Monster{
public:
    Vampire();
    char getToken();
    virtual void moveAround();
    virtual int getHealth();
    void setHealth(int newHealth);
    void receiveDamage(int playerDamage);
    int getAttack();

    int health = 100;
    int attack = 20;
    int loot = 15;

    void death();
    void setToken(char theToken);
    int deathStatus();
    void setLoot(int gold);
    int getLoot();


private:

    char _token =  'M';
    char _liveToken = 'V';
    char _lootToken = '*';
    int _isDead = 0;
};

