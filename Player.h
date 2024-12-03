#ifndef PLAYER_H
#define PLAYER_H

#include "Food.h"
#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Food;
class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.
    public:
        //Enum represents the possible directions a player can move
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP}; 

        //Constructor for the Player class. Takes  GameMechs and Food object references
        Player(GameMechs* thisGMRef, Food* thisFoodRef); 

        //Destructor of Player Class
        ~Player();

        //Returns an objPosArrayList pointer to the players list of positions
        objPosArrayList* getPlayerPos() const; 

        //Updates player direction based on input/logic
        void updatePlayerDir();

        //Moves player in current direction
        void movePlayer();

        //Returns current player score
        int getScore() const;

    private:
        objPosArrayList* playerPosList; // holds the array list of player positions   
        enum Dir myDir;                 // holds the current direction of player

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
        Food* mainFoodRef;

};

#endif