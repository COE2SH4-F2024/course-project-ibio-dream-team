#include "Player.h"
#include "Food.h"
#include "MacUILib.h"
#include <iostream>

//CONSTRUCTOR
Player::Player(GameMechs* thisGMRef, Food* thisFoodRef)
{
    mainGameMechsRef = thisGMRef; 
    mainFoodRef = thisFoodRef;
    myDir = STOP;               //set inital player direction to stop, so when game starts the snake doesn't move

    playerPosList = new objPosArrayList();


    objPos playerpos = objPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*');
    playerPosList-> insertHead(playerpos) ;

}

//DESTRUCTOR
Player::~Player()
{
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos() const
{
    return playerPosList;  // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    //taking input from the keys and assigning a specific direction to each input (Same as PPA input logic processing)
    // w = UP, s = DOWN, a = LEFT, d = RIGHT
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
        
}

void Player::movePlayer()
{
    objPos currentHead = objPos(playerPosList->getHeadElement());
    objPosArrayList* foodBuckPos = mainFoodRef->getFoodBucket();

    //Setting the current x and y positions of the snake head 
    int currentHeadX= currentHead.pos->x;
    int currentHeadY= currentHead.pos->y;

    //Setting the border wraparound constants based on the size of the game board in x and y directions
    int boardWrapX = mainGameMechsRef->getBoardSizeX() - 1;
    int boardWrapY = mainGameMechsRef->getBoardSizeY() - 1;

    //Updating the Head Position of the snake depending on the input direction
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


    //Border Wrap-Around logic when snake reaches edge of game screen 
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


    //New head position at the updated x and y positions according to the most recent direction input
    //snakeEnd is holding the position of each snake element behind the head that we will iterate through to check if game is lost.
    objPos newHead(currentHeadX,currentHeadY,'*');
    objPos snakeEnd;


    //Loop through every element of the snake to check if the head is colliding with 
    for(int i = 1; i < playerPosList->getSize(); i++)
    {
        snakeEnd = playerPosList->getElement(i); 

        //check if the new head position is colliding with the an element of the snake.
        if(newHead.pos->x == snakeEnd.pos->x && newHead.pos->y == snakeEnd.pos->y)
        {
            mainGameMechsRef->setExitTrue();
            mainGameMechsRef->setLoseFlag();
            return;
        }
    }

    //insert a new head at the position the snake head is moving towards according the the last directional input (WASD)
    playerPosList->insertHead(newHead);
    bool foodConsumed = false;

    //loop through each food item in food bucket.
    for(int i = 0; i < foodBuckPos->getSize(); i++ )  
    {
        //Check if each item is at the same position as the new inserted Head
        if(foodBuckPos->getElement(i).isPosEqual(&newHead))
        {

            if(foodBuckPos->getElement(i).getSymbol() == '+')
            {
                // if the snake head collides with a '+' food, then insert 2 additional snake heads, 
                // to make the '+' increase snake length by 3
                for(int i =0; i<2;i++)
                {
                    playerPosList->insertHead(newHead);
                }

            }

            //Regenerate the Food Bucket in 5 new random spots on the board after collision.
            mainFoodRef->generateFood(mainGameMechsRef, playerPosList);
            mainGameMechsRef->incrementScore();
            foodConsumed = true;
            break;
        }

    }

    //Check if there was NO collision between the food and snake head 
    if(!foodConsumed)
    {
        // If there was NO collision and the snake head is larger than 1 then we take away the tail to cancel the new head insertion and keep the snake at the same size.
        if (playerPosList->getSize() > 1) {
            playerPosList->removeTail();
        }
    }

    
}

//Gets the current score from the game mechanics reference 
int Player::getScore() const
{
    return mainGameMechsRef->getScore();
}