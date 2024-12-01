#ifndef FOOD_H
#define FOOD_H
#include <cstdlib>
#include <time.h>
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Player.h"
#include "MacUILib.h"

using namespace std;

class Food{
    private:
        objPos foodPos;
        objPosArrayList *foodBucket;
    
    public:
        Food();
        ~Food();
        objPos const getFoodPos();
        void generateFood(GameMechs* gameMechsPtr, objPosArrayList* blockOff);
        objPosArrayList* getFoodBucket();
};

#endif

