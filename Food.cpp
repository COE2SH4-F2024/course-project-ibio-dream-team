#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"
#include <stdio.h>

Food::Food(){
    foodPos.symbol = 'o';
    foodPos.setObjPos(0,0, foodPos.symbol);
    foodBucket = new objPosArrayList(5);
}

Food::~Food(){
    delete foodBucket;
}

void Food::generateFood(GameMechs* gameMechsPtr, objPosArrayList* blockOff)
{

    srand(static_cast<unsigned int>(time(0)));
    bool valid = false;
    int numOfItems = 0;
    int foodX, foodY;

    while(numOfItems <= 5){
        int foodX = rand() % ((gameMechsPtr->getBoardSizeX()) - 2) + 1;
        int foodY = rand() % ((gameMechsPtr->getBoardSizeY()) - 2) + 1;
        char foodSymbol = rand() % (126 - 33 + 1) + 33;

        while(!valid){
            valid = true;
            for(int i = 0; i < blockOff->getSize(); i++){
                objPos snakePos = blockOff->getElement(i);
                if(foodX == snakePos.pos -> x && foodY == snakePos.pos -> y){
                        valid = false;
                        foodX = rand() % ((gameMechsPtr->getBoardSizeX()) - 2) + 1;
                        foodY = rand() % ((gameMechsPtr->getBoardSizeY()) - 2) + 1;
                        break; //breaking since as soon as the food item overlaps with one part of snake, it needs new rand x and y values
                    }        
                }
                //keep generating symbols until they're not invalid
                while(foodSymbol == '*' || foodSymbol == '|' || foodSymbol == '='){
                    foodSymbol = rand() % (126 - 33 + 1) + 33;
                }
                //check if symbol or x-y coordinates alr exists in bucket
                for (int i = 0; i < foodBucket->getSize(); i++){
                    objPos itemToCheck = foodBucket->getElement(i).getObjPos();
                    if(itemToCheck.symbol == foodSymbol || itemToCheck.pos -> x == foodX && itemToCheck.pos -> y == foodY){
                        valid = false;
                        break;
                    }
                }
            }
        }
        foodPos.setObjPos(foodX, foodY, foodPos.symbol);
        foodBucket -> setElement(numOfItems, foodPos);
        numOfItems++;     
    // foodPos.setObjPos(foodX,foodY,'o');
}

objPos const Food::getFoodPos(){
    return foodPos;
}