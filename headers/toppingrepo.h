#ifndef TOPPINGREPO_H
#define TOPPINGREPO_H

#define toppingfile "data/toppings.dat"

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
    private:
        FileHandler<Topping>* toppinglist;

};

#endif
