#ifndef PIZZA_H
#define PIZZA_H
#include <iostream>
#include "product.h"
#include "topping.h"
class Pizza : public Product {
    public:
        Pizza();
        Pizza(char n[sizeOfName],int topping);
        virtual ~Pizza();
        virtual int GetNumberOfToppings() const;
        void AddTopping(Topping topping);

        friend std::ostream& operator<<(std::ostream &os, Pizza& pizza);
        // friend std::istream& operator>>(std::istream &is, Product &prod);

    private:
        int numberOfToppings;
        int currTopping;
        Topping *toppings;

};
#endif
