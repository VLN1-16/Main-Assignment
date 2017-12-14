#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <cmath>
#include <string>
#include "product.h"
#include "topping.h"
#include "pizzasize.h"

class NoSizes{};
class Pizza : public Product {
    public:
        Pizza();
        Pizza(const Pizza& from);
        Pizza(char n[lengthOfName], int Price = 1000, double Offset = 1.4, int Size = 16) ;
        Pizza(char n[lengthOfName], Pizzasize& Pizzasize);
        Pizza(std::string name, Pizzasize& Pizzasize);

        virtual ~Pizza();
        void AddTopping(const Topping topping, const bool calcOffset = true, const bool free = false);

        int GetPrice() const;
        int GetSize() const;
        int GetStatus() const;
        int GetOffset() const;
        int SetSize(const int& newsize);
        int GetNumberOfToppings() const;

        bool operator ==(const Pizza& pizza);
        Pizza& operator=(const Pizza& from);
        friend std::ostream& operator<<(std::ostream &os, Pizza& pizza);
        friend std::istream& operator>>(std::istream &is, Pizza& pizza);

        virtual void WriteBin(std::ostream& BinaryOut);
        virtual void ReadBin (std::istream& BinaryIn);

        void SetStatus(int status);
    private:
        void resize();
        int numberOfToppings;
        int currTopping;
        int size;
        double offset;
        Topping *toppings;
        int progress; // 0 not started, 1 in Progress, Evrything else (normally 2) Pizza is ready,

};
#endif
