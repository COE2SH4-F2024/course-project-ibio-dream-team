#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    earlyEnd = false;
    score = 0;
    

    boardSizeX = 30;
    boardSizeY = 15; 
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    earlyEnd = false;
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
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;

}

void GameMechs::clearInput()
{
    input = 0;
}



// More methods should be added here

void GameMechs::collectAsyncInput()
{
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }

    
}

void GameMechs::setEarlyEnd()
{
    earlyEnd = true;
}

bool GameMechs::getEarlyEndStatus()
{
    return earlyEnd;
}