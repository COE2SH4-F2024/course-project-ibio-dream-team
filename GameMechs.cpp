#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = 20;
    boardSizeY = 10; 
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = boardX;
    boardSizeY = boardY;

}

// do you need a destructor?
GameMechs::~GameMechs()
{
    //currently no because no new
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    
void GameMechs::collectAsyncInput()
{
    if (MacUILib_hasChar() == 1)
    {
        input = MacUILib_getChar();
    }
    
    if(input == ' ')
    {
        exitFlag = 1;
    } 
}

char GameMechs::getInput() //const  // becuase the CONST is here you can not alter anything
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = 1;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    if(MacUILib_hasChar())
    {
        this_input = MacUILib_getChar();
    }

}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here