#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <tuple>
#include <ctime>
#include <random>
#include "Player.h"
#include "Monster.h"

using namespace std;

class Map

{
public:
    Map();      //Constructor
    void load(string levelName);
    void obtainSpawningLocations(char characterToken, Character &aCharacter);
    void checkMovementMonsters(char input, Monster &aMonster);
    void print();
    void checkMovement(char input, Character &aCharacter);
    void movement(char characterToken);
    char returnLocation(int x,int y);
    char getch();
    char randomChar();
    void moveMonsters();
    void battlePlayerMonster(Player thePlayer, Monster &theMonster);

    void movePlayer();
    int findTheRightMonster(int x,int y);
    void printPlayerInfo();
    void deleteTheMonster(Monster &theMonster);

private:
    int _spawnValue;
    vector <string> _mapData;
    Player _player;
    Monster* _monsterPointers[5];

};
