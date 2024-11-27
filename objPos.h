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
        Pos* pos;
        /// not sure if x and y needs to be here i just added it
        int x;
        int y;  
        ////////////////      
        char symbol;

        //default constructor
        objPos();
        //additional constructor
        objPos(int xPos, int yPos, char sym);
        //copy constructor
        objPos(const objPos &thisPos); //deep copy
        //destructor
        ~objPos();
        //copy assignment operator overload
        objPos& operator=(const objPos &obj);
        // Respect the rule of six / minimum four
        // [TODO] Implement the missing special member functions to meet the minimum four rule
       





        
        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  

        objPos getObjPos() const;
        char getSymbol() const;
        char getSymbolIfPosEqual(const objPos* refPos) const;
        
        bool isPosEqual(const objPos* refPos) const;
};

#endif