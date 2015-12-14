#include "serviceconnected.h"

ServiceConnected::ServiceConnected()
{
    conList = list <Connected>();
}

list <Connected> ServiceConnected::getConection()
{
    return conList;
}

list <Connected> ServiceConnected::findConnectons(string stringSearch)
{
    string x = stringSearch;  //hefur enga virkni
    // conList = db.eithvað fall sem leitar(nameSearch);

    return conList;
}

list <Connected> ServiceConnected::viewSciToCom()
{
    conList = db.AllScientistToComputer();
    return conList;
}

bool ServiceConnected::connectSciToCom(int scientistId, int computerId)
{
    bool result;
    if(db.conncetScientistToComputer(scientistId, computerId))
    {
        result = true;
    }
    else
    {
        result = false;
    }
    return result;
}
