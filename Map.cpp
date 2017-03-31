#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <cstring>
#include <random>
#include <ctime>
#include <tuple>
#include "Map.h"
#include <time.h>
#include "Monster.h"
#include "Werewolf.h"
#include "Vampire.h"
#include <unistd.h>
//#include <curses.h>
//#include <conio.h>
#include <termios.h>

Map::Map(){
srand (time(NULL));
}

void Map::load(string levelName){
    ifstream theStream;
    theStream.open(levelName);

    if(theStream.fail()){
        perror(levelName.c_str());
        system("PAUSE");
        exit(1);
    }

    string line;
    while(getline(theStream, line)){
    _mapData.push_back(line);
    }
        theStream.close();

for(int i = 0; i < 5; i++){
    _spawnValue = rand() % 2;   //We generate either 1 or 2

    if(_spawnValue==1){
        _monsterPointers[i] = new Werewolf();
    }
    else{
        _monsterPointers[i] = new Vampire();
    }
        obtainSpawningLocations(_monsterPointers[i]->getToken(),*_monsterPointers[i]);
    //WE NEED TO DELETE THESE POINTERS EVENTUALLY!!!

}

        obtainSpawningLocations(_player.getToken(),_player);

}


void Map::obtainSpawningLocations(char characterToken,Character &_character){
/*
Below code provides all the possible spawning locations for the player
and stores them in an array of tuples.
*/

tuple<int,int> myTuple[600];    //Hard coded 600 value is messy.  Change later

int numberOfSpawnPoints = 0;
int upperLimitForNumberGenerator = 0;
/*
The for loop below records all of the possible spawning locations and stores them in the tuple array
*/
    for(int i = 0; i<_mapData.size();i++){
        for(int j = 0; j<_mapData[i].size();j++){
            if(_mapData[i][j]=='.'){
                    get<0>(myTuple[numberOfSpawnPoints]) = j;
                    get<1>(myTuple[numberOfSpawnPoints]) = i;
                    numberOfSpawnPoints++;
                    }
                }
    }
upperLimitForNumberGenerator = numberOfSpawnPoints;

int characterCoordinates = rand()%upperLimitForNumberGenerator;

int xCoordinate = get<0>(myTuple[characterCoordinates]);
int yCoordinate = get<1>(myTuple[characterCoordinates]);

_mapData[yCoordinate][xCoordinate] = characterToken;   //Remember y is first and x is second

_character.setLocation(xCoordinate, yCoordinate);
}


void Map::print(){
    for(int i=0;i<_mapData.size(); i++){
        printf("%s\n", _mapData[i].c_str());
    }
    printf("\n");
}



void Map::checkMovement(char input, Character &aCharacter){   //&aCharacter is a reference.  That is,
//it is a direct link to the memory location that stores
//that value.
/*
Remember: C++ is naturally a pass BY VALUE.
Pass by value is when we pass copies of the value.
*/

/*
This function only checks for walls at the moment.
We need to provide a switch statement for battle
with monsters at some point.
*/

/*
We need a function that goes through the map and returns the player location.
How do we do this for monsters?
*/

/*
So we need a setter and getter for character location

Remember: a reference parameter will CHANGE the passed value EVEN if there's no return.

Consider GameChallenge 3 at 36:30 for full explanation.
Also this:
https://www.youtube.com/watch?v=X9-a-MiMwEI
*/


int x;
int y;

aCharacter.getLocation(x,y);
if(aCharacter.deathStatus()==0){


char aLocation;

switch(input) {
    case 'w':
    case 'W':   //If 1 up from the player token is a '.' then we move him up
                //via a different function
                //Otherwise we do nothing.
                aLocation = returnLocation(x,y-1);
                switch(aLocation){

                case '.':
                    _mapData[y][x] = '.';
                    _mapData[y-1][x] = aCharacter.getToken();
                    aCharacter.setLocation(x,y-1);
                    break;
                case '#':
                    break;

                case '*':

                    aCharacter.setLoot(_monsterPointers[findTheRightMonster((x),(y-1))]->getLoot());

                    _monsterPointers[findTheRightMonster(x,(y-1))]->setToken('#');

                    _monsterPointers[findTheRightMonster(x,(y-1))]->setLocation(0,0);

                    _mapData[y][x] = '.';
                    _mapData[y-1][x] = aCharacter.getToken();
                    aCharacter.setLocation(x,y-1);
                    break;

                default:
                    if(aCharacter.getToken()=='@'){
                    battlePlayerMonster(_player,*_monsterPointers[findTheRightMonster(x,(y-1))]);
                }
                    else{
                    cout<<"battleMonsterMonster"<<endl;
                    }
                }

        break;

    case 'a':
    case 'A':
                aLocation = returnLocation(x-1,y);

                 switch(aLocation){

                case '.':
                    _mapData[y][x] = '.';
                    _mapData[y][x-1] = aCharacter.getToken();
                    aCharacter.setLocation(x-1,y);
                    break;
                case '#':
                    break;

                case '*':
                   aCharacter.setLoot(_monsterPointers[findTheRightMonster((x-1),(y))]->getLoot());
                    _monsterPointers[findTheRightMonster((x-1),(y))]->setToken('#');
                    _monsterPointers[findTheRightMonster((x-1),(y))]->setLocation(0,0);

                    _mapData[y][x] = '.';
                    _mapData[y][x-1] = aCharacter.getToken();
                    aCharacter.setLocation(x-1,y);

                    break;

                default:
                    if(aCharacter.getToken()=='@'){
                    battlePlayerMonster(_player,*_monsterPointers[findTheRightMonster((x-1),y)]);
                }
                    else{
                    cout<<"battleMonsterMonster"<<endl;
                    }
                }

        break;
    case 's':
    case 'S':

                aLocation = returnLocation(x,y+1);

                 switch(aLocation){

                case '.':
                    _mapData[y][x] = '.';
                    _mapData[y+1][x] = aCharacter.getToken();
                    aCharacter.setLocation(x,y+1);
                    break;
                case '#':

                    break;

                case '*':
                    aCharacter.setLoot(_monsterPointers[findTheRightMonster((x),(y+1))]->getLoot());

                    _monsterPointers[findTheRightMonster(x,(y+1))]->setToken('#');  //lol

                    _monsterPointers[findTheRightMonster(x,(y+1))]->setLocation(0,0);   //lol

                    _mapData[y][x] = '.';
                    _mapData[y+1][x] = aCharacter.getToken();
                    aCharacter.setLocation(x,y+1);

                    break;
                default:
                    if(aCharacter.getToken()=='@'){
                    battlePlayerMonster(_player,*_monsterPointers[findTheRightMonster(x,(y+1))]);
                    }
                    else{
                    cout<<"battleMonsterMonster"<<endl;
                    }
                }

        break;
    case 'd':
    case 'D':
                aLocation = returnLocation(x+1,y);

                 switch(aLocation){

                case '.':
                    _mapData[y][x] = '.';
                    _mapData[y][x+1] = aCharacter.getToken();
                    aCharacter.setLocation(x+1,y);
                    break;
                case '#':
                    break;

                case '*':

                   aCharacter.setLoot(_monsterPointers[findTheRightMonster((x+1),(y))]->getLoot());

                    _monsterPointers[findTheRightMonster((x+1),(y))]->setToken('#');

                    _monsterPointers[findTheRightMonster((x+1),(y))]->setLocation(0,0);
                    _mapData[y][x] = '.';
                    _mapData[y][x+1] = aCharacter.getToken();
                    aCharacter.setLocation(x+1,y);

                    break;

                default:
                    if(aCharacter.getToken()=='@'){
                    battlePlayerMonster(_player,*_monsterPointers[findTheRightMonster((x+1),y)]);
                    }
                    else{
                    cout<<"battleMonsterMonster"<<endl;
                    }

                }
        break;
    default:
        cout<<"Invalid input";
        system("PAUSE");
        break;
    }
    }

    else{
        _mapData[y][x]=aCharacter.getToken();
    }
}


void checkMonsterLocation(int x, int y){
    for(int i = 0; i < 5; i++){

        }

}

char Map::returnLocation(int x, int y){
char aSpot = _mapData[y][x];
return aSpot;
}

int Map::findTheRightMonster(int x, int y){ //x and y are the defenders coordinates

//This function returns the monster we're dealing with.
/*
This function should return either a monster or a player
*/

int possibleX;
int possibleY;

    for(int i = 0; i < 5; i++){
        _monsterPointers[i]->getLocation(possibleX,possibleY);     //The getLocation will be any given characters coordinates
            if((possibleX ==x)&&(possibleY==y)){
                cout<<"The monster in question is: "<<_monsterPointers[i]->getToken()<<endl;
                return i;
                break;
                    }
            }
}

void Map::battlePlayerMonster(Player thePlayer, Monster &theMonster){

int monsterHealth = theMonster.getHealth();
monsterHealth = monsterHealth-thePlayer.getAttack();
theMonster.setHealth(monsterHealth);

}

void Map::moveMonsters(){
char randomDirection;

    for(int i = 0; i <5; i++){
        randomDirection = randomChar();
        checkMovement(randomDirection, *_monsterPointers[i]);
        }
}

void Map::printPlayerInfo(){
printf("Health: %d\n",_player.health);
printf("Gold: %d\n",_player.getLoot());

}

char Map::randomChar(){
    char achar;
    int randomNumber = rand() % 4;     //4 possible outcomes: 0,1,2,3

    switch(randomNumber){
    case 0:     //do stuff
            achar = 'w';
    break;

    case 1:     //do stuff
            achar = 's';
    break;

    case 2:     //do stuff
            achar = 'a';
    break;

    case 3:     //do stuff
            achar = 'd';
    break;
}
    return achar;
}

char Map::getch(){

    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        {perror("tcsetattr()");}
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        {perror("tcsetattr ICANON");}
    if(read(0,&buf,1)<0)
        {perror("read()");}
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        {perror ("tcsetattr ~ICANON");}
    //printf("%c\n",buf);
    return buf;
 }


void Map::movePlayer(){
    char input;
    input = getch();
    string clearScreenString(100,'\n'); //Prints out a newLine char 100 times
    cout << clearScreenString;
    checkMovement(input, _player);
}
