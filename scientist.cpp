#include "scientist.h"


Scientist::Scientist()
{

}

Scientist::Scientist(string aName, string aGender, int aBirthYear, int aDeathYear)
{
    id = 0;
    name = aName;
    gender = aGender;
    birthYear = aBirthYear;
    deathYear = aDeathYear;
}

int Scientist::getId() const
{
    return id;
}

string Scientist::getName() const
{
    return name;
}

string Scientist::getGender() const
{
    return gender;
}

int Scientist::getBirthYear() const
{
    return birthYear;
}

int Scientist::getDeathYear() const
{
    return deathYear;
}
