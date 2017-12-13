#ifndef PIZZASIZEREPO_H
#define PIZZASIZEREPO_H

#include "config.h"
#include "topping.h"
#include "pizza.h"
#include "filehandler.h"

class PizzaSizeRepo{
    public:
        PizzaSizeRepo();
        ~PizzaSizeRepo();
        void AddPizzaSize(Pizzasize s);
        void GetPizzaSizes(std::ostream &os);
        void DeletePizzaSizeat(int index);
        Pizzasize GetPizzaSizeat(int index);
        Pizzasize GetPizzaSize(int index);
    private:
        FileHandler<Pizzasize>* pizzasizelist;
};
#endif
