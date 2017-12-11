#ifndef PIZZAREPO_H
#define PIZZAREPO_H

#define pizzafile "data/pizzamenu.dat"

#include <iostream>
#include "pizza.h"
#include "topping.h"
#include "product.h"

class PizzaRepo {
    public:
        void AddPizza(Pizza& pizza);
        void GetPizzas(std::ostream &os);

    private:
        FileHandler<Pizza>* pizzamenu;
};
#endif
