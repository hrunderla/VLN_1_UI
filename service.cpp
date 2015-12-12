#include "service.h"


Service::Service()
{
   sciList = list <Scientist>();
}

list <Scientist> Service::getList()
{
    return sciList;
}

list <Scientist> Service::viewScientistAsc()
{
    //list <Scientist> temp = sciList;
    sciList = db.sortScientistsAlpabetically();
    return sciList;
}

list <Scientist> Service::findData(string nameSearch)
{
    sciList = db.searchScientists(nameSearch);

    return sciList;
}

list <Scientist> Service::findDataFull(string nameSearch)
{
    sciList = db.searchScientistsId(nameSearch);

    return sciList;
}
void Service::newScientist(Scientist newScientist)
{
    db.add(newScientist);
}


