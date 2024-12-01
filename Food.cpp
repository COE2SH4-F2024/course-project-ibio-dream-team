#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"
#include <stdio.h>

Food::Food(){
    srand(static_cast<unsigned int>(time(0))); // Seed only once
    foodBucket = new objPosArrayList();
}

Food::~Food(){
    delete foodBucket;
}

void Food::generateFood(GameMechs* gameMechsPtr, objPosArrayList* blockOff)
{
    int numOfItems = 0;
    int foodX, foodY;
    char foodSymbol;

    while(numOfItems < 5){
        bool valid = false;
        while(!valid){
            valid = true;
            foodX = rand() % ((gameMechsPtr->getBoardSizeX()) - 2) + 1;
            foodY = rand() % ((gameMechsPtr->getBoardSizeY()) - 2) + 1;
            foodSymbol = rand() % (126 - 33 + 1) + 33;

            for(int i = 0; i < blockOff->getSize(); i++){
                objPos snakePos = blockOff->getElement(i);
                if(foodX == snakePos.pos -> x && foodY == snakePos.pos -> y){
                        valid = false;
                        break; //breaking since as soon as the food item overlaps with one part of snake, it needs new rand x and y values
                    }        
                }

                //keep generating symbols until they're not invalid
                while(foodSymbol == '*' || foodSymbol == '|' || foodSymbol == '='){
                    foodSymbol = rand() % (126 - 33 + 1) + 33;
                }
                //check if symbol or x-y coordinates alr exists in bucket
                for (int i = 0; i < foodBucket->getSize(); i++){
                    objPos itemToCheck = foodBucket->getElement(i);
                    if(itemToCheck.pos -> x == foodX && itemToCheck.pos -> y == foodY){
                        valid = false;
                        break;
                    }
                    if(itemToCheck.symbol == foodSymbol){
                        valid = false;
                        break;
                    }
                }
                       
            }
            objPos foodItem(foodX, foodY, foodSymbol);
            foodBucket->insertTail(foodItem);
            numOfItems++;
        }
    }
          
    // foodPos.setObjPos(foodX,foodY,'o');

//return last used food position
objPos const Food::getFoodPos(){
    if (foodBucket->getSize() > 0) {
        return foodBucket->getElement(foodBucket->getSize() - 1);
    }
}