#ifndef INACTIVEORDERREPO_H
#define INACTIVEORDERREPO_H

#include "config.h"
#include "order.h"
#include "filehandler.h"
#include "place.h"

class InActiveOrderRepo{
    public:
        InActiveOrderRepo();
        ~InActiveOrderRepo();
        void GetOrders(std::ostream &os);
        void AddOrder(Order &order);
        int GetNumberOfOrders() const;
    private:
        FileHandler<Order>* orderList;
};
#endif
