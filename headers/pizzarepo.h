#ifndef PIZZAREPO_H
#define PIZZAREPO_H

#define pizzafile "data/pizzamenu.dat"

#include <iostream>
#include "filehandler.h"
#include "pizza.h"
#include "topping.h"
#include "product.h"

class PizzaRepo {
    public:
        PizzaRepo();
        ~PizzaRepo();
        void AddPizza(Pizza& pizza);
        void GetPizzas(std::ostream &os);
        Pizza GetPizza(int index);

    private:
        FileHandler<Pizza>* pizzamenu;
};
#endif
