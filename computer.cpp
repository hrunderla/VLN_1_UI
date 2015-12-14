#include "computer.h"

Computer::Computer()
{
    id = 0;
    name = "";
    year = 0;
    type = "";
    built = false;
    info ="";

}

Computer::Computer(string aName, int aYear, string aType, bool wasItBuilt)
{
    id = 0;
    name = aName;
    year = aYear;
    type = aType;
    built = wasItBuilt;
}

Computer::Computer(int anId, string aName, int aYear, string aType, bool wasItBuilt)
{
    id = anId;
    name = aName;
    year = aYear;
    type = aType;
    built = wasItBuilt;

}

int Computer::getId() const
{
    return id;
}

int Computer::putId(int anId)
{
    id = anId;
}

string Computer::getName() const
{
    return name;
}

int Computer::getYear() const
{
    return year;
}

string Computer::getType() const
{
    return type;
}

bool Computer::getwasItBuilt() const
{
    return built;
}
