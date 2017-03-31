#include <iostream>
#include <string>
#include "Werewolf.h"

using namespace std;

Werewolf::Werewolf(){
    setToken(_liveToken);
}

char Werewolf::getToken(){
    return _token;
}

void Werewolf::moveAround(){
}

void Werewolf::receiveDamage(int playerDamage){
    health = health-playerDamage;

}
int Werewolf::getHealth(){
    cout<<health<<endl;

return health;
}

void Werewolf::setHealth(int newHealth){
    health = newHealth;
   // cout<<"Werewolf health = "<<health<<endl;
    if(health <= 0){
           death(); }
}

int Werewolf::getAttack(){
return attack;
}

void Werewolf::setToken(char theToken){
    _token = theToken;
}

void Werewolf::death(){
    setToken(_lootToken);
    _isDead = 1;     //This isn't sticking around for some reason
}

int Werewolf::deathStatus(){
    return _isDead;
}

void Werewolf::setLoot(int gold){
    loot = loot+gold;
}

int Werewolf::getLoot(){
    return loot;
}

