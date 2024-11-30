#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"

Food::Food(){
    foodPos.symbol = 'o';
    foodPos.setObjPos(0,0, foodPos.symbol);
}

Food::~Food(){

}

void Food::generateFood(GameMechs* gameMechsPtr, objPosArrayList* blockOff)
{

    srand(static_cast<unsigned int>(time(0)));
    bool valid = false;
    int foodX = rand() % ((gameMechsPtr->getBoardSizeX()) - 2) + 1;
    int foodY = rand() % ((gameMechsPtr->getBoardSizeY()) - 2) + 1;

    while(!valid){
        valid = true;
        for(int i = 0; i < blockOff->getSize(); i++){
            objPos snakePos = blockOff->getElement(i);
            if(foodX == snakePos.pos -> x && foodY == snakePos.pos -> y){
                    valid = false;
                    foodX = rand() % ((gameMechsPtr->getBoardSizeX()) - 2) + 1;
                    foodY = rand() % ((gameMechsPtr->getBoardSizeY()) - 2) + 1;
                }        
            }
        } 
    foodPos.setObjPos(foodX,foodY,'o');
}

objPos const Food::getFoodPos(){
    return foodPos;
}