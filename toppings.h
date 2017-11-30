#ifndef TOPPINGS_H
#define TOPPINGS_H
#define arraySize 10
#include <stddef.h>
#include "topping.h"
class Toppings {
    public:
        Toppings();
        ~Topping();
        void AddTopping(Topping tp);
        friend std::ostream& operator<<(std::ostream &os, Toppings &topp);
        friend std::istream& operator>>(std::istream &is, Toppings &topp);
    private:
        Topping toppingList[arraySize];
        void Resize();
        int size;
        int numberOfToppings;

};
#endif
