#ifndef OBJPOS_H
#define OBJPOS_H

// Not really a C++ thing
typedef struct 
{
    int x;
    int y;
} Pos;

class objPos
{
    public:
        //pointer to a Pos object and character symbol of object
        Pos* pos;      
        char symbol;

        // Respect the rule of six / minimum four

        //default constructor
        objPos();

        //additional constructor
        objPos(int xPos, int yPos, char sym);
        
        //destructor
        ~objPos();

        //copy constructor
        objPos(const objPos &thisPos);

        //copy assignment operator
        objPos& operator=(const objPos &obj);

        //Sets position and the symbol of current object to match another object
        void setObjPos(objPos o);   

        //Sets the position and symbol using explicit x,y, and symbol     
        void setObjPos(int xPos, int yPos, char sym);  

        //returns copy of current position object
        objPos getObjPos() const;

        //returns symbol of current object
        char getSymbol() const;

        //if position of current obj matches reference obj passed return current symbol, otherwise return null
        char getSymbolIfPosEqual(const objPos* refPos) const;
        
        //compares the position of current obj to another reference obj to see if equal
        bool isPosEqual(const objPos* refPos) const;
};

#endif