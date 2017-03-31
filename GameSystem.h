#pragma once
#include "Map.h"
#include <string>
#include <list>

using namespace std;

class GameSystem
{

public:
    GameSystem(string mapName);       //Constructor

    void startGame();    //Start the game
    char getch();
    void movePlayer();
    char randomChar();
    void moveMonsters();

//    void setMonsters(incomingMonsters[]);
  //  void getMonsters(&askingForMonsters[]);

private:

    //int _numberOfMonsters = 5;    //We'll make this a random number later
    Map _map;
    Player _player;
//    Monster _monster;
 //  Monster _theMonsters[5];       //Variable sized arrays DO work but only with newer compilers
    /*
    Why does Monster* _monsterPointers[5]; work and not
    Monster _monster;?
    Answer:
    http://stackoverflow.com/questions/5821075/why-do-virtual-functions-need-to-be-passed-with-a-pointer-and-not-by-valueof-th
    */
    Monster* _monsterPointers[5];   //USE DYNAMIC ARRAYS!!!!! Watch ben tut on subject
    //You delete what you new
    //DON'T USE MALLOC WHEN USING C++!!

    //http://stackoverflow.com/questions/184537/in-what-cases-do-i-use-malloc-vs-new
    /*
    Dynamic array fun fact:

    int input;
    cin >> input;

    int *myArray = new int[input];
    *myArray is a stack variable, int[input] is on heap.

    Also remember: Anytime we call new we have to use delete!
    */


    int _x;
    int _y;
    int _spawnValue;
};

//Constructor initializes the game


