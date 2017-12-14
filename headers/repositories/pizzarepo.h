#ifndef PIZZAREPO_H
#define PIZZAREPO_H

#include "filehandler.h"
#include "pizza.h"
#include "topping.h"
#include "product.h"
#include "config.h"

#include <iostream>

class PizzaRepo {
    public:
        PizzaRepo();
        ~PizzaRepo();
        void AddPizza(Pizza& pizza);
        void GetPizzas(std::ostream &os);
        Pizza GetPizza(int index);
        int GetNumberOfPizzas() const;
        void RemovePizza(int index);
    private:
        FileHandler<Pizza>* pizzamenu;
};
#endif
