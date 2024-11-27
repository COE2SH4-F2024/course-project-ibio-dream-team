#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

Player *myPlayer;
GameMechs *myGM;


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
    myPlayer = new Player(myGM);
}

void GetInput(void)
{
    //myGM->setInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    objPos playerPos = myPlayer->getPlayerPos();
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<20;j++)
        {
            if(i==0 || i==9 || j==0 || j==19)
            {
                MacUILib_printf("#"); 
            }
            else if(i == playerPos.pos->y && j == playerPos.pos->x)
            {
                MacUILib_printf("%c",playerPos.symbol); 
            }
            else
            {
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

    MacUILib_uninit();
}
