#include <iostream>
#include <string>
#include "Monster.h"

using namespace std;

Monster::Monster(){

}
void Monster::moveAround(){
}

int Monster::getHealth(){

}

void Monster::setHealth(int health){

}

void Monster::setToken(char theToken){

}

void Monster::setLoot(int gold){
    loot = loot+gold;
}

int Monster::getLoot(){
    return loot;
}
void Monster::death(){

}
