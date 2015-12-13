#include "servicecomputer.h"

ServiceComputer::ServiceComputer()
{
   comList = list <Computer>();
}

list <Computer> ServiceComputer::getComputerList()
{
    return comList;
}

list <Computer> ServiceComputer::findDataComp(string nameSearch)
{
    comList = db.searchComputers(nameSearch);

    return comList;
}

/**********************************henda notum likleag ekki*************
list <Computer> ServiceComputer::findDataFull(string nameSearch)
{
    comList = db.searchComputerId(nameSearch);

    return comList;
}
***********************************************************************/

list <Computer> ServiceComputer::viewComputerAsc()
{
    comList = db.sortComputersAsc();

    return comList;
}

void ServiceComputer::newComputer(Computer newComputer)
{
    db.addComputer(newComputer);
}
