#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "GameMechs.h"
#include "Player.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

Player *myPlayer;
GameMechs *myGM;
Food *foodItem;


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(30,15);
    foodItem = new Food();
    myPlayer = new Player(myGM,foodItem);
    
    foodItem->generateFood(myGM, myPlayer->getPlayerPos());
}

void GetInput(void)
{
    myGM->collectAsyncInput();
    // if(myGM->getInput()== ' ')
    // {
    //     foodItem->generateFood(myGM, myPlayer->getPlayerPos());
    // }
    if(myGM->getInput() == 27)
    {
        myGM->setExitTrue();
    }
    
    // if (MacUILib_hasChar() == 1)
    // {
    //     myGM -> setInput(MacUILib_getChar());
    //     // if(myGM->getInput() == 27)
    //     // {
    //     //     myGM->setExitTrue();
    //     // }
    //     if(myGM->getInput() == ' ')
    //     {
    //         foodItem->generateFood(myGM,myPlayer->getPlayerPos());
    //     }
    //     // else if(myGM->getInput() == ' ')
    //     // {
    //     //     foodItem->generateFood(myGM, myPlayer->getPlayerPos());
    //     // }
    // }
    // else
    //     myGM->clearInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    myGM->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    MacUILib_printf("           Welcome to the 2SH4 Snake Game!\n");
    MacUILib_printf("WASD to move, ESC to exit the game, get all the food items!\n");

    objPosArrayList* foodBucket = foodItem->getFoodBucket();;
    objPos snakebody;
    for(int y = 0; y < myGM->getBoardSizeY(); y++)
    {
        for(int x = 0; x < myGM->getBoardSizeX(); x++)
        {
            if(y == 0 || y == myGM->getBoardSizeY() - 1)
                MacUILib_printf("=");

            else if(x == 0 || x ==  myGM->getBoardSizeX() - 1)
                MacUILib_printf("|");

            else{
                int printingHere = 0; //flag to check, changed name from onSnake to be used for foodBucket
                for(int i = 0; i <  myPlayer->getPlayerPos()->getSize(); i++){
                    snakebody.setObjPos(myPlayer->getPlayerPos()->getElement(i));//objPos snakebody = myPlayer->getPlayerPos()->getElement(i);
                    if(x == snakebody.pos->x && y == snakebody.pos->y){
                        MacUILib_printf("%c", snakebody.symbol);
                        printingHere = 1; //this location is part of the snake's body
                        break; //break since only one segment of the snake's body exists per one pair of x and y coordinates
                        }
                    }

                    if (printingHere == 0){ //meaning if this x and y pair is NOT on a location where snakebody sits
                        for(int i = 0; i < foodBucket->getSize(); i++){
                            if (x == foodBucket->getElement(i).pos->x && y == foodBucket->getElement(i).pos->y) {
                                MacUILib_printf("%c", foodBucket->getElement(i).symbol);
                                printingHere = 1;
                            }
                        }

                        if(!printingHere){
                             MacUILib_printf(" ");
                        }
                    }
                }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("Score: %d\n", myPlayer->getScore());
    MacUILib_printf("Player Head Position[x,y] = [%d,%d]", myPlayer->getPlayerPos()->getHeadElement().pos->x, 
                    myPlayer->getPlayerPos()->getHeadElement().pos->y);

    if(myGM->getExitFlagStatus())
    {
        MacUILib_printf("\nYOU ARE A QUITTER! Game Exited\n");
    }

    if (myGM->getLoseFlagStatus())
    {
        MacUILib_printf("\nOH NO! Unfortunately you have LOST! Please try again.\n");
    }

                    
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(void)
{

    delete myPlayer;
    delete myGM;
    delete foodItem;

    MacUILib_uninit();
}
