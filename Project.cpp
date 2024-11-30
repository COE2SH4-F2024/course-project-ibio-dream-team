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

    myGM = new GameMechs();                 ///pointer objects defined
    foodItem = new Food();
    myPlayer = new Player(myGM);
}

void GetInput(void)
{
    myGM->getInput();
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
    objPos playerPos = myPlayer->getPlayerPos();
    for(int i = 0; i < myGM->getBoardSizeY(); i++)
    {
        for(int j = 0; j < myGM->getBoardSizeX(); j++)
        {
            if(i == 0 || i == myGM->getBoardSizeY() - 1)
                MacUILib_printf("=");

            else if(j == 0 || j == myGM->getBoardSizeX() - 1)
                MacUILib_printf("|");

            else if(j == playerPos.pos->x && i == playerPos.pos->y)
                MacUILib_printf("%c", playerPos.symbol);
            else{
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("Player[x,y] = [%d,%d], %c",
                    playerPos.pos->x, playerPos.pos->y,playerPos.symbol);
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
