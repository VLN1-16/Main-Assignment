#ifndef DELIVERY_H
#define DELIVERY_H

#define activeorderfile "data/orderfile.dat"
#define inactiveorderfile "data/inactiveorders.dat"
#include "topping.h"
#include "order.h"
#include "filehandler.h"
#include <string>
#include "place.h"
class Delivery{
    public:
        Delivery(Place place);
        ~Delivery();
        void GetOrders(std::ostream& os);
        void GetReadyOrders(std::ostream& os);
        void MarkDelivered(int index);
        void GetThisOrder(std::ostream& os,int orderid);
        void MarkPaid(int index);

    private:
        FileHandler<Order>* activeorders;
        FileHandler<Order>* inactiveorders;
        Place myplace;
};

#endif
