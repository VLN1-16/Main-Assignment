#ifndef PREPERATOR_H
#define PREPERATOR_H

#define orderfile "data/orderfile.dat"
#include "topping.h"
#include "order.h"
#include "filehandler.h"
#include <vector>
#include "place.h"
#include "exceptions.h"
class Preperator{
    public:
        Preperator(Place myplace);
        ~Preperator();
        void GetPizza(std::ostream& os, int index);
        void MarkDone(int index);
        void loadVec();
        void UpdateStatus(int index, int status);
    private:
        std::vector<Pizza> pizzas;
        FileHandler<Order>* activeorders;
        Place myplace;
};

#endif
