#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


// Object Computer with appropriate variebles set:
// string Name, string gender, int year of birth, int year of death

class Computer
{
    public:
        // Default compiler.
        Computer();

        // Compiler that takes in all four variebles in Computer
        Computer(string aName, int aYear, string aType, bool wasItBuilt);

        // Compiler that takes in all four variebles in Computer
        Computer(int anId, string aName, int aYear, string aType, bool wasItBuilt);

        // returns id used in database.
        int getId() const;

        int putId(int anId);

        // returns name.
        string getName() const;

        // returns type.
        string getType() const;

        // returns year.
        int getYear() const;

        // returns bool value if computer was built.
        bool getwasItBuilt() const;

        // operator << overwritten to print Computer
        friend ostream& operator << (ostream& outs, const Computer& Computer);

        string toString();

        string info;
private:

        string name, type;
        int id, year;
        bool built;
};

#endif // COMPUTER_H
