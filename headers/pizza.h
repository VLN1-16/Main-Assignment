#ifndef PIZZA_H
#define PIZZA_H
#include <iostream>
#include "math.h"
#include "product.h"
#include "topping.h"
class NoSizes{};
class Pizza : public Product {
    public:
        Pizza();
        Pizza(char n[sizeOfName], int Price = 1000, double Offset = 1.4, int Size = 16) ;
        virtual ~Pizza();
        void AddTopping(Topping topping, bool calcOffset = true, bool free = false);

        int GetPrice() const;
        int GetSize() const;
        int SetSize(const int& newsize);
        int GetNumberOfToppings() const;

        bool operator ==(const Pizza& pizza);
        friend std::ostream& operator<<(std::ostream &os, Pizza& pizza);
        friend std::istream& operator>>(std::istream &is, Pizza& pizza);

        virtual void WriteBin(std::ostream& BinaryOut);
        virtual void ReadBin (std::istream& BinaryIn);

    private:
        void resize();
        int numberOfToppings;
        int currTopping;
        int size;
        double offset;
        Topping *toppings;

};
#endif
