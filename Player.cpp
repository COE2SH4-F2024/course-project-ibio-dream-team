#include "Player.h"
#include "MacUILib.h"
#include <iostream>


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    playerPosList = new objPosArrayList();
    objPos initSnake = objPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, 'o');
    playerPosList->insertTail(initSnake);
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
                }
                break;
    
            case 's':
                if(myDir != UP)
                {
                    myDir = DOWN;  
                }
                break;
                
            case 'a':
                if(myDir != RIGHT)
                {
                    myDir = LEFT;  
                }
                break;

            case 'd':
                if(myDir!= LEFT)
                {
                    myDir = RIGHT;   
                }
                break;

        }
        // PPA3 input processing logic          
}

void Player::movePlayer()
{
    if(myDir == UP)
    {
        playerPos.pos->y-=2; 
    }
    else if(myDir == DOWN)
    {
        playerPos.pos->y+=2;
    }
    else if(myDir == LEFT)
    {
        playerPos.pos->x-=2;
    }
    else if(myDir == RIGHT)
    {
        playerPos.pos->x+=2;  
    }

    int boardWrapX = mainGameMechsRef->getBoardSizeX() - 1;
    int boardWrapY = mainGameMechsRef->getBoardSizeY() - 1;

    if( playerPos.pos->x <= 0)
    {
        playerPos.pos->x  += boardWrapX - 1;
    }
    else if (playerPos.pos->x >= boardWrapX)
    {
        playerPos.pos->x -= boardWrapX - 1;
    }

    if(playerPos.pos->y  <= 0)
    {
        playerPos.pos->y  += boardWrapY - 1;
    }
    else if (playerPos.pos->y >= boardWrapY)
    {
        playerPos.pos->y -= boardWrapY - 1;
    }  
    // PPA3 Finite State Machine logic
}

// More methods to be added