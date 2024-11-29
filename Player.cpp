#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    playerPos.pos->x = mainGameMechsRef->getBoardSizeX()/2; //center of board thats why /2
    playerPos.pos->y = mainGameMechsRef->getBoardSizeY()/2;
    playerPos.symbol = '@';
    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
    // no keyword "new" in constructor therefore no destructor for now
}

objPos Player::getPlayerPos() const
{
    return playerPos;  
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
        playerPos.pos->y--; 
    }
    else if(myDir == DOWN)
    {
        playerPos.pos->y++;
    }
    else if(myDir == LEFT)
    {
        playerPos.pos->x--;
    }
    else if(myDir == RIGHT)
    {
        playerPos.pos->x++;  
    }

    int boardWrapX = mainGameMechsRef->getBoardSizeX() - 1;
    int boardWrapY = mainGameMechsRef->getBoardSizeY() - 1;

    if( playerPos.pos->x == 0)
    {
        playerPos.pos->x  += boardWrapX - 1;
    }
    else if (playerPos.pos->x == boardWrapX)
    {
        playerPos.pos->x -= boardWrapX - 1;
    }

    if(playerPos.pos->y  == 0)
    {
        playerPos.pos->y  += boardWrapY - 1;
    }
    else if (playerPos.pos->y == boardWrapY)
    {
        playerPos.pos->y -= boardWrapY - 1;
    }  
    // PPA3 Finite State Machine logic
}

// More methods to be added