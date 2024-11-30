#include "Player.h"
#include "Food.h"
#include "MacUILib.h"
#include <iostream>


Player::Player(GameMechs* thisGMRef, Food* thisFoodRef)
{
    mainGameMechsRef = thisGMRef; 
    mainFoodRef = thisFoodRef;
    myDir = STOP;

    playerPosList = new objPosArrayList();


    objPos playerpos = objPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*');
    playerPosList-> insertHead(playerpos) ;  ////insertTail(playerpos);
    // more actions to be included
// 
}


Player::~Player()
{
    // delete any heap members here
    delete [] playerPosList;
    // no keyword "new" in constructor therefore no destructor for now
}

objPosArrayList* Player::getPlayerPos() const
{
    return playerPosList;
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput();
    switch(input)
        {                      
            case 'w':
                if(myDir != DOWN)
                {
                    myDir = UP;
                    break;
                }else
                    break;
    
            case 's':
                if(myDir != UP)
                {
                    myDir = DOWN;
                    break;  
                }else
                    break;
                
            case 'a':
                if(myDir != RIGHT)
                {
                    myDir = LEFT;
                    break;  
                }else
                    break;

            case 'd':
                if(myDir!= LEFT)
                {
                    myDir = RIGHT;
                    break;   
                }else
                    break;
        

        }
        // PPA3 input processing logic 
}

void Player::movePlayer()
{
    objPos currentHead = objPos(playerPosList->getHeadElement());
    objPos foodPosition = mainFoodRef->getFoodPos();

    int currentHeadX= currentHead.pos->x;
    int currentHeadY= currentHead.pos->y;

    if(myDir == UP)
    {
        currentHeadY--; 
    }
    else if(myDir == DOWN)
    {
        currentHeadY++;
    }
    else if(myDir == LEFT)
    {
        currentHeadX--;
    }
    else if(myDir == RIGHT)
    {
        currentHeadX++;  
    }

    int boardWrapX = mainGameMechsRef->getBoardSizeX() - 1;
    int boardWrapY = mainGameMechsRef->getBoardSizeY() - 1;

    if( currentHeadX <= 0)
    {
        currentHeadX  += boardWrapX - 1;
    }
    else if (currentHead.pos->x >= boardWrapX)
    {
        currentHeadX -= boardWrapX - 1;
    }

    if(currentHeadY  <= 0)
    {
        currentHeadY  += boardWrapY - 1;
    }
    else if (currentHeadY >= boardWrapY)
    {
        currentHeadY -= boardWrapY - 1;
    }  
    // PPA3 Finite State Machine logic


    //New head position
    objPos newHead(currentHeadX,currentHeadY,'*');
    playerPosList->insertHead(newHead);
    if(!foodPosition.isPosEqual(&newHead))
    {
        playerPosList->removeTail();
    }
    else
    {
        mainFoodRef->generateFood(mainGameMechsRef, playerPosList);
    }
}

// More methods to be added

int Player::getScore() const
{
    return playerPosList->getSize() - 1;
}