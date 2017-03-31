#pragma once
#include <string>
#include "Character.h"      //For inheritance/polymorphism
#include "Monster.h"


class Werewolf: public Monster{
public:
    Werewolf();
    char getToken();
    void moveAround();
    void receiveDamage(int playerDamage);

    virtual int getHealth();

    int health = 150;
    int attack = 10;
    int loot = 20;
    void setHealth(int newHealth);
    int getAttack();
    void setToken(char theToken);
    void death();
    int deathStatus();
    void setLoot(int gold);
    int getLoot();


private:

    char _token = 'M';
    char _liveToken = 'T';
    char _lootToken = '*';
    int _isDead = 0;

};
