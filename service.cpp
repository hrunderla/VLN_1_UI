#include "service.h"


Service::Service()
{
   sciList = list <Scientist>();
}

list <Scientist> Service::getList()
{
    return sciList;
}

/*
void Service::putList(list <Scientist> inputList)
{
    sciList = inputList;
} */


Scientist Service::extract (string aString)
{
    aString.c_str();
    char SYMBOL = ',';
    int pos1 = 0;
    size_t pos2 = aString.find(SYMBOL);
    size_t pos3 = aString.find(SYMBOL, pos2 + 1);
    size_t pos4 = aString.find(SYMBOL, pos3 + 1);

    string name = aString.substr(pos1, pos2);
    string gender = aString.substr(pos2+1, pos3-pos2-1);
    string bYear = aString.substr(pos3+1, pos4-pos2-1);
    string dYear = aString.substr(pos3+1, pos4-pos2-1); //eftir að laga

    bYear.c_str();
    dYear.c_str();

    /*char birth [bYear.size()];
    for(unsigned int i = 0; i<bYear.size(); i++){
        birth[i] = bYear[i];
    }

    char death [dYear.size()];
    for(unsigned int i = 0; i<dYear.size(); i++){
        death[i]=dYear[i];
    }
*/
    int birthYear = atoi(bYear.c_str());
    int deathYear = atoi(dYear.c_str());

    Scientist sciInfo (name, gender, birthYear, deathYear);

return sciInfo;
}

list <Scientist> Service::viewScientistAlphabetically()
{
    //list <Scientist> temp = sciList;
    sciList = db.sortScientistsAlpabetically();
    return sciList;
}

list <Scientist> Service::viewScientistReverse()
{
    //list <Scientist> temp = sciList;
    sciList = db.sortScientistsReverse();
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


