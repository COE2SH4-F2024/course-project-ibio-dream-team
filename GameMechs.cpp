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
    

char GameMechs::getInput() //const  // becuase the CONST is here you can not alter anything
{
    if (MacUILib_hasChar() == 1)
    {
        input = MacUILib_getChar();
    }
    
    if(input == ' ')
    {
        exitFlag = 1;
    }

    return input;
}

int GameMechs::getScore() const
{

}

void GameMechs::incrementScore()
{
    
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

}

void GameMechs::setLoseFlag()
{
    
}

void GameMechs::setInput(char this_input)
{

}

void GameMechs::clearInput()
{

}

// More methods should be added here