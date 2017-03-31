#include <iostream>
#include <string>
#include "GameSystem.h"
#include "Map.h"
#include "Player.h"
#include "Werewolf.h"
#include "Vampire.h"
//#include "conio.h"
#include <cstdio>
#include <stdio.h>

#include <time.h>

GameSystem::GameSystem(string mapName){

    srand (time(NULL));

    _map.load(mapName);

}

/*
We have to make sure that the player can move around.  Use getch.
The map will accept user input and move the players token based on switch statements
*/

void GameSystem::startGame(){
    bool isOver = false;
        while(isOver!=true){
            _map.printPlayerInfo();
            _map.print();
            _map.movePlayer();
            _map.moveMonsters();
           }
}


