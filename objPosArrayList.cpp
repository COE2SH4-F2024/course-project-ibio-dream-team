#include "objPosArrayList.h"
#include <iostream>

using namespace std;

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    arrayCapacity = ARRAY_MAX_CAP;
    aList = new objPos[arrayCapacity];
    listSize = 0;
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize==arrayCapacity)
    {
        cout << "Warning! Array list full, no insertion allowed!" << endl;
        return;
    }

    for(int i = listSize; i>0; i--)
    {
        aList[i] = aList[i-1];
    }

    aList[0] = thisPos;
    listSize++;
        
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize==arrayCapacity)
    {
        cout << "Warning! Array list full, no insertion allowed!" << endl;
        return;
    }
    aList[listSize] = thisPos;
    listSize++;
}

void objPosArrayList::removeHead()
{

    if(listSize == 0)
    {
        cout << "Warning! No elements in list to remove!"<< endl;
        return;
    }

    for(int i = 0; i<listSize-1;i++)
    {
        aList[i] = aList[i+1];
    }
    listSize--;
    
}

void objPosArrayList::removeTail()
{
    if(listSize == 0)
    {
        cout << "Warning! List is empty, no elements to remove" << endl;
        return;
    }

    listSize--;
}

objPos objPosArrayList::getHeadElement() const
{
    if(listSize > 0)
    {
        return aList[0];
    }
}

objPos objPosArrayList::getTailElement() const
{
    if(listSize > 0)
    {
        return aList[listSize-1];
    }
    
}

objPos objPosArrayList::getElement(int index) const
{
    if(index<0)
    {
        return aList[0];
    }
    else if(index >= listSize && listSize != 0)
    {
        return aList[listSize - 1];
    }
    
    return aList[index];
}
// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.
