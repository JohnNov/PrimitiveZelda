#include <iostream>
#include <string>
#include "Vampire.h"

using namespace std;

//Updated Vampire in master branch!  This should show up in a fetch.

Vampire::Vampire(){
    setToken(_liveToken);
}

char Vampire::getToken(){
    return _token;
}

void Vampire::moveAround(){
}

void Vampire::receiveDamage(int playerDamage){
    health = health-playerDamage;

}
 int Vampire::getHealth(){
    return health;
}

void Vampire::setHealth(int newHealth){
    health = newHealth;
   // cout<<"Vampire health = "<<health<<endl;
     if(health <= 0){
           death();
           }
}

int Vampire::getAttack(){
return attack;
}
void Vampire::death(){
    setToken(_lootToken);
    _isDead = 1;
}

void Vampire::setToken(char theToken){
    _token = theToken;
}

int Vampire::deathStatus(){
    return _isDead;
}

void Vampire::setLoot(int gold){
    loot = loot+gold;
}

int Vampire::getLoot(){
    return loot;
}
