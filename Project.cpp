#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* gameMechs;
bool exitflag = 1;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(!gameMechs->getExitFlagStatus())  
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

    gameMechs = new GameMechs(30, 15);
}

void GetInput(void)
{
    gameMechs->getInput();
}

void RunLogic(void)
{
    if(gameMechs->getInput()){
        switch(gameMechs->getInput()){
            case 27:  //ESC to exit
                gameMechs->setExitTrue();
                break;
            
            default:
                break;
        }
        gameMechs->clearInput();
    }
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();
    delete gameMechs;
    gameMechs = nullptr;    

    MacUILib_uninit();
}
