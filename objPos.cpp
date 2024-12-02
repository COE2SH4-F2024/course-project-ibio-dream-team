#include "objPos.h"
#include <iostream>

using namespace std;

// Respect the rule of six / minimum four

//DEFAULT CONSTRUCTOR
objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

//ADDITIONAL CONSTRUCTOR
objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

//DESTRUCTOR
objPos::~objPos()
{
    delete pos;
}

//COPY CONSTRUCTOR
objPos::objPos(const objPos &thisPos)
{
    pos = new Pos;
    //// is this a deep copy
    
    pos->x = thisPos.pos->x;
    pos->y = thisPos.pos->y;
    symbol = thisPos.symbol;
}

//COPY ASSIGNMENT OPERATOR 
objPos& objPos::operator=(const objPos &thisPos)
{
    if (this != nullptr)
    {
        if(pos != nullptr)
        {
            delete pos;
        }
        
        pos = new Pos;
        pos->x = thisPos.pos->x;
        pos->y = thisPos.pos->y;
        symbol = thisPos.symbol;
    }

    return *this;   
}

//Other member functions

//Sets position and symbol of current object to match those of another
void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

//Sets position and symbol using explicit x, y, and symbol passed through
void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

//Returns a copy of the current position object
objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

//Returns the symbol of the current position object
char objPos::getSymbol() const
{
    return symbol;
}

//Compares the current position object with the reference position to see if equal
bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

//If the current position is equal to the reference position, return the symbol of the current object
// otherwise return null character
char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}
