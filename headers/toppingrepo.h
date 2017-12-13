#ifndef TOPPINGREPO_H
#define TOPPINGREPO_H

#include "config.h"
#include "filehandler.h"
#include "topping.h"

class ToppingRepo{
    public:
        ToppingRepo();
        ~ToppingRepo();
        void AddTopping(Topping topping);
        void GetToppings(std::ostream &os);
        void RemoveTopping(int index);
        Topping GetToppingat(int index);
        Topping GetTopping(int index);
    private:
        FileHandler<Topping>* toppinglist;

};

#endif
