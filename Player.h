#ifndef PLAYER_H
#define PLAYER_H

#include "Food.h"
#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Food;
class Player
{
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* thisFoodRef); 
        ~Player();

        objPosArrayList* getPlayerPos() const; //      
        void updatePlayerDir();
        void movePlayer();

        // More methods to be added here
        int getScore() const;

    private:
        objPosArrayList* playerPosList; // Upgrade this in iteration 3.       
        enum Dir myDir;

        //reference to the Main Game Mechanisms and Food class
        GameMechs* mainGameMechsRef;
        Food* mainFoodRef;

};

#endif