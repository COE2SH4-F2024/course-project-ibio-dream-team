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
    myPlayer = new Player(myGM);
    
    foodItem->generateFood(myGM, myPlayer->getPlayerPos());
}

void GetInput(void)
{
    if (MacUILib_hasChar()){
        myGM -> setInput(MacUILib_getChar());
        if(myGM->getInput() == 27)
            myGM->setExitTrue();
        else if(myGM->getInput() == ' ')
            foodItem->generateFood(myGM, myPlayer->getPlayerPos());
    }else
        myGM->clearInput();
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
    objPos FoodPos = foodItem->getFoodPos();;

    for(int y = 0; y < myGM->getBoardSizeY(); y++)
    {
        for(int x = 0; x < myGM->getBoardSizeX(); x++)
        {
            if(y == 0 || y == myGM->getBoardSizeY() - 1)
                MacUILib_printf("=");

            else if(x == 0 || x ==  myGM->getBoardSizeX() - 1)
                MacUILib_printf("|");

            else{
                int onSnakeBody = 0; //flag to check
                for(int i = 0; i <  myPlayer->getPlayerPos()->getSize(); i++){
                    objPos snakebody = myPlayer->getPlayerPos()->getElement(i);
                    if(x == snakebody.pos->x && y == snakebody.pos->y){
                        MacUILib_printf("%c", snakebody.symbol);
                        onSnakeBody = 1; //this location is part of the snake's body
                        break; //break since only one segment of the snake's body exists per one pair of x and y coordinates
                        }
                    }

                    if (onSnakeBody == 0){ //meaning if this x and y pair is NOT on a location where snakebody sits
                        if (x == FoodPos.pos->x && y == FoodPos.pos->y) {
                            MacUILib_printf("%c", FoodPos.symbol);
                        }
                    }
                }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("Player Head Position[x,y] = [%d,%d], %c",
                    myPlayer->getPlayerPos()->getHeadElement().pos->x, myPlayer->getPlayerPos()->getHeadElement().pos->y, '@');
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();  

    delete myPlayer;
    delete myGM;
    delete foodItem;

    MacUILib_uninit();
}
