#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"
#include <iostream>

using namespace std;

Food::Food(){
    foodPos.x = 0;
    foodPos.y = 0;
    foodPos.symbol = 'o'; // Default symbol
}

Food::~Food(){

}

void Food::generateFood(GameMechs* gameMechsPtr, objPos blockOff)
{
    srand(static_cast<unsigned int>(time(0)));
    bool valid = false;
    int foodX = rand() % ((gameMechsPtr->getBoardSizeX()) - 2) + 1;
    int foodY = rand() % ((gameMechsPtr->getBoardSizeY()) - 2) + 1;

    while(!valid){
        valid = true;
        if(foodX == blockOff.pos -> x && foodY == blockOff.pos -> y){
                valid = false;
                foodX = rand() % ((gameMechsPtr->getBoardSizeX()) - 2) + 1;
                foodY = rand() % ((gameMechsPtr->getBoardSizeY()) - 2) + 1;
                
        }
    } 
    foodPos.setObjPos(foodX,foodY,'o');
}


objPos const Food::getFoodPos(){
    return foodPos;
}