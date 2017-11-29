#ifndef COSTUMER_H
#define COSTUMER_H
#define lengthOfName 50
#include <iostream>

class Costumer{
    public:
        Costumer();
        Costumer(char FirstName[lengthOfName], char LastName[lengthOfName]);
        friend std::ostream& operator <<(std::ostream& out, Costumer& cost);
        friend std::ifstream& operator >>(std::ifstream& is, Costumer& cost);
    private:
        char firstName[lengthOfName];
        char lastName[lengthOfName];
};

#endif
