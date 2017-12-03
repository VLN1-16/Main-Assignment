#ifndef COSTUMER_H
#define COSTUMER_H
#define lengthOfName 50
#include <iostream>

class badnumber{};
class Costumer{
    public:
        Costumer();
        Costumer(char FirstName[lengthOfName], char LastName[lengthOfName], char Number[8]);
        friend std::ostream& operator <<(std::ostream& out, Costumer& cost);
        friend std::istream& operator >>(std::istream& is, Costumer& cost);
        void WriteBin(std::ostream& out);
        void ReadBin (std::istream& is);
    private:
        char firstName[lengthOfName];
        char lastName[lengthOfName];
        char number[8];
};

#endif
