#ifndef PIZZASIZE_H
#define PIZZASIZE_H

#include "math.h"

#include <iostream>

class Pizzasize {
    public:
        Pizzasize();
        Pizzasize(int s, double Offset, int Price);
        int GetPrice();
        double GetOffset();
        int GetSize();
        void IsSizeValid(int size);
        friend std::ostream& operator<<(std::ostream &os, Pizzasize& ps);

        virtual void WriteBin(std::ostream& binaryOut);
        virtual void ReadBin (std::istream& binaryIn);


    private:
        int size;
        double offset;
        int price;

};
#endif
