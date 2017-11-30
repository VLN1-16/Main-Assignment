#ifndef TOPPINGS_H
#define TOPPINGS_H
#define arraySize 10
#define toppingDatatFile "pizzatoppings.obj"
#include <stddef.h>
#include <fstream>
#include "topping.h"
class Toppings {
    public:
        Toppings();
        ~Toppings();
        void AddTopping(Topping tp,bool toFile = true);
        int GetSize();
        friend std::ostream& operator<<(std::ostream &os, Toppings &topp);
    private:
        Topping *toppingList;
        void Resize();
        int size;
        int numberOfToppings;


};
#endif
