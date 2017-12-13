#ifndef COSTUMER_H
#define COSTUMER_H
#define lengthOfName 50
#include <iostream>

#include "iscostumernamevalid.h"

class badnumber{};
class Costumer{
    public:
        Costumer();
        Costumer(char FirstName[lengthOfName], char LastName[lengthOfName], char Number[8]);
        friend std::ostream& operator <<(std::ostream& out, Costumer& cost);
        friend std::istream& operator >>(std::istream& is, Costumer& cost);
        const char* GetFirstName();
        const char* GetLastName();
        const char* GetNumber();
        const bool CompareNumber(const char n[8]);
        void SetFirstName(const char newFirstName[lengthOfName]);
        void SetLastName(const char newLastName[lengthOfName]);
        // This throws a badnumber if the number is not good
        void SetNumber(const char newNumber[8]);
        void WriteBin(std::ostream& out);
        void ReadBin (std::istream& is);
        bool operator ==(Costumer& cost);
    private:
        bool NumberIsOk(const char numberToCheck[8]);
        char firstName[lengthOfName];
        char lastName[lengthOfName];
        char number[8];
};

#endif
