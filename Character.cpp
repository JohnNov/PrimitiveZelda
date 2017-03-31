#include <string>
#include "Character.h"

using namespace std;


Character::Character(){

}


char Character::getToken(){
}

void Character::setLocation(int x, int y){
_x = x;
_y = y;
}

void Character::getLocation(int &x, int &y){
x = _x;
y = _y;
}

int Character::getHealth(){
}
void Character::setHealth(int attack){
}

int Character::getAttack(){
return attack;
}

void Character::setLoot(int gold){
    loot = loot+gold;
}

int Character::getLoot(){
    return loot;
}

int Character::deathStatus(){
}
