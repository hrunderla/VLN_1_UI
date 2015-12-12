#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Object Scientist with appropriate variebles set:
// string Name, string gender, int year of birth, int year of death

class Scientist
{
    public:
        // Initializes the list
        Scientist();

        // combines Name, gender, year of birth
        Scientist(string aName, string aGender, int aBirthYear, int aDeathYear);

        int getId() const;
        string getName() const;
        string getGender() const;
        int getBirthYear() const;
        int getDeathYear() const;

private:
        string name, gender;
        int id, birthYear, deathYear;
};

#endif // SCIENTIST_H
