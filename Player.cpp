/*
In order to randomly spawn a player we've gotta be able to keep track of all the
locations that the player can travel ('.')

We need to go through the map and every time we come across a plain dot we store its
location in the vector AND we keep track of how many dots we've got.

So for example we have 50 dots then we do a random number generator from 1-50.  If
for example we get a 23 then we spawn the player at whatever location the 23'rd dot
is at!


So what should we use to store this?


WAIT FIRST LETS SPAWN THE PLAYER AT A HARD CODED LOCATION!


*/
#include <iostream>
#include <string>
#include "Player.h"


Player::Player(){

}

char Player::getToken(){
    return _token;
}

void Player::receiveDamage(int monsterDamage){
    health = health-monsterDamage;
    }

int Player::getHealth(){
    cout<<"300"<<endl;
    return health;

}
void Player::setHealth(int damage){
    health = health-damage;
}

int Player::deathStatus(){
    return _isDead;
}

void Player::setLoot(int gold){
    loot = loot+gold;
}

int Player::getLoot(){
    return loot;
}


int Player::getAttack(){
    return attack;
}
