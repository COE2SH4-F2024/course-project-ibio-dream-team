#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"
#include <stdio.h>

Food::Food(){
    srand(static_cast<unsigned int>(time(0))); // Seed only once
    foodBucket = new objPosArrayList(5);
}

Food::~Food(){
    delete[] foodBucket;
}

void Food::generateFood(GameMechs* gameMechsPtr, objPosArrayList* blockOff)
{
    foodBucket->clearArray(); //clear out previous food bucket
    int specialItems = 0;
    int foodX, foodY;
    char foodSymbol;

    //generating 2 special items
    while(specialItems < 2){
        bool valid = false;
        while(!valid){
            valid = true;
            foodX = rand() % ((gameMechsPtr->getBoardSizeX()) - 2) + 1;
            foodY = rand() % ((gameMechsPtr->getBoardSizeY()) - 2) + 1;
            foodSymbol = '+';

            for(int i = 0; i < blockOff->getSize(); i++){
                objPos snakePos = blockOff->getElement(i);
                if(foodX == snakePos.pos -> x && foodY == snakePos.pos -> y){
                        valid = false;
                        break; //breaking since as soon as the food item overlaps with one part of snake, it needs new rand x and y values
                    }        
                }

                // //keep generating symbols until they're not invalid
                // while(foodSymbol == '*' || foodSymbol == '|' || foodSymbol == '='){
                //     foodSymbol = rand() % (126 - 33 + 1) + 33;
                // }
                //check if symbol or x-y coordinates alr exists in bucket
                for (int i = 0; i < foodBucket->getSize(); i++){
                    objPos itemToCheck = foodBucket->getElement(i);
                    if(itemToCheck.pos -> x == foodX && itemToCheck.pos -> y == foodY){
                        valid = false;
                        break;
                    }
                    // if(itemToCheck.symbol == foodSymbol){
                    //     valid = false;
                    //     break;
                    // }
                }
                       
            }
            objPos specialFoods(foodX, foodY, foodSymbol);
            foodBucket->insertTail(specialFoods);
            specialItems++;
    }

    int normalItems = 0;
    while(normalItems < 3){
        bool valid = false;
        while(!valid){
            valid = true;
            foodX = rand() % ((gameMechsPtr->getBoardSizeX()) - 2) + 1;
            foodY = rand() % ((gameMechsPtr->getBoardSizeY()) - 2) + 1;

            for(int i = 2; i < blockOff->getSize(); i++){
                objPos snakePos = blockOff->getElement(i);
                if(foodX == snakePos.pos -> x && foodY == snakePos.pos -> y){
                        valid = false;
                        break; //breaking since as soon as the food item overlaps with one part of snake, it needs new rand x and y values
                    }        
                }
            //check for duplicated x and y positions
            for (int i = 0; i < foodBucket->getSize(); i++){
                    objPos itemToCheck = foodBucket->getElement(i);
                    if(itemToCheck.pos -> x == foodX && itemToCheck.pos -> y == foodY){
                        valid = false;
                        break;
                    }
            }
        }
        objPos normalFoods(foodX, foodY, 'o' );
        foodBucket->insertTail(normalFoods);
        normalItems++;
}
}
          
    // foodPos.setObjPos(foodX,foodY,'o');

//return last used food position
objPos const Food::getFoodPos(){
    if (foodBucket->getSize() > 0) {
        return foodBucket->getElement(foodBucket->getSize() - 1);
    }
}

//return foodbucket
objPosArrayList* Food::getFoodBucket() {
    return foodBucket;
}