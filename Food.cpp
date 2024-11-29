#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"

Food::Food(){

}

Food::~Food(){

}

void Food::generateFood(GameMechs* gameMechsPtr, objPos blockOff)
{

    srand(static_cast<unsigned int>(time(0)));
    while(foodPos.x != 0 && foodPos.y != 0 && foodPos.x != gameMechsPtr->getBoardSizeX() && 
        foodPos.y != gameMechsPtr->getBoardSizeY() && foodPos.x != blockOff.x && foodPos.y != blockOff.y){

            foodPos.x = rand() % ((gameMechsPtr->getBoardSizeX()) - 2) + 1;
            foodPos.y = rand() % ((gameMechsPtr->getBoardSizeY()) - 2) + 1;
            foodPos.symbol = 'o';
            
        } 
}

void Food::getFoodPos(objPos &foodpos){
    foodpos.getObjPos();
}