#ifndef DELIVERY_H
#define DELIVERY_H

#define activeorderfile "data/orderfile.dat"
#define inactiveorderfile "data/inactiveorders.dat"
#include "topping.h"
#include "order.h"
#include "filehandler.h"
#include <vector>
#include "place.h"
class Delivery{
    public:
        Delivery(Place place);
        ~Delivery();
        void GetOrders(std::ostream& os);
        void MarkDelivered(int index);

    private:
        std::vector<Order> activeorders;
        FileHandler<Order>* orders;
        FileHandler<Order>* inactiveorders;
        Place myplace;
};

#endif
