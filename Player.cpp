#include "Player.h"
#include "MacUILib.h"
#include <iostream>


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    playerPosList = new objPosArrayList();
    objPos playerpos = objPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, 'o');
    playerPosList->insertTail(playerpos);
    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
    // no keyword "new" in constructor therefore no destructor for now
}

objPosArrayList* Player::getPlayerPos() const
{
    return playerPosList;
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{

    switch(mainGameMechsRef->getInput())
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
    objPos currentHead = playerPosList->getHeadElement();
    if(myDir == UP)
    {
        currentHead.pos->y-=2; 
    }
    else if(myDir == DOWN)
    {
        currentHead.pos->y+=2;
    }
    else if(myDir == LEFT)
    {
        currentHead.pos->x-=2;
    }
    else if(myDir == RIGHT)
    {
        currentHead.pos->x+=2;  
    }

    int boardWrapX = mainGameMechsRef->getBoardSizeX() - 1;
    int boardWrapY = mainGameMechsRef->getBoardSizeY() - 1;

    if( currentHead.pos->x <= 0)
    {
        currentHead.pos->x  += boardWrapX - 1;
    }
    else if (currentHead.pos->x >= boardWrapX)
    {
        currentHead.pos->x -= boardWrapX - 1;
    }

    if(currentHead.pos->y  <= 0)
    {
        currentHead.pos->y  += boardWrapY - 1;
    }
    else if (currentHead.pos->y >= boardWrapY)
    {
        currentHead.pos->y -= boardWrapY - 1;
    }  
    // PPA3 Finite State Machine logic
}

// More methods to be added