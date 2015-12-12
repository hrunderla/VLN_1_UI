#ifndef SERVICE_H
#define SERVICE_H
#include "scientist.h"
#include "database.h"
#include <string>
#include <list>
#include <cstdlib>

using namespace std;

class Service
{
public:
     // Initializes the list
    Service();

    // Returns sciList
    list <Scientist> getList();

    // sends new instance of scientist to databaselayer
    void newScientist(Scientist newScientist);

    // Allows the user to search in the list
    list <Scientist> findData(string name);

    list <Scientist> findDataFull(string nameSearch); // má mjög líklega henda

    list <Scientist> viewScientistAsc();

private:

    list <Scientist> sciList;

    Database db;
};

#endif // SERVICE_H
