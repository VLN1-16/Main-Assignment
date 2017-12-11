#ifndef ORDERREPO_H
#define ORDERREPO_H

#define orderfile "data/orderfile.dat"

#include "pizza.h"
#include "topping.h"
#include "product.h"
#include "order.h"
#include "filehandler.h"

class OrderRepo{
    public:
        OrderRepo();
        ~OrderRepo();
        void GetActiveOrders(std::ostream &os);
        void AddOrder(Order &order);
        Order GetOrderAt(int index);
    private:
        FileHandler<Order>* orderList;        
};
#endif
