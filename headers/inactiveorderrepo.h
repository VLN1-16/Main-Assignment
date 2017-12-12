#ifndef INACTIVEORDERREPO_H
#define INACTIVEORDERREPO_H

#define inactiveorderfile "data/inactiveorders.dat"

#include "order.h"
#include "filehandler.h"
#include "place.h"


class InActiveOrderRepo{
    public:
        InActiveOrderRepo();
        ~InActiveOrderRepo();
        void GetOrders(std::ostream &os);
        void AddOrder(Order &order);



    private:
        FileHandler<Order>* orderList;
};
#endif
