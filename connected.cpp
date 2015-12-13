#include "connected.h"

Connected::Connected()
{
    nameOne = "";
    nameTwo = "";
    idOne = 0;
    idTwo = 0;
}
Connected::Connected(string name1, string name2)
{
    nameOne = name1;
    nameTwo = name2;
    idOne = 0;
    idTwo = 0;
}

void Connected::putNameOne(int anId)
{
    idOne = anId;
}

void Connected::putNameTwo(int anId)
{
    idTwo = anId;
}

string Connected::getNameOne() const
{
    return nameOne;
}

string Connected::getNameTwo() const
{
    return nameTwo;
}

ostream& operator << (ostream& outs, const Connected& Connected)
{
    outs << setw(40);
    outs.setf(ios::left);
    outs << Connected.nameOne;
            outs << setw(40);
            outs.setf(ios::left);
       outs  << Connected.nameTwo;

    return outs;
}
