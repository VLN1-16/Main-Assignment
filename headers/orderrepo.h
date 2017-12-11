#ifndef ORDERREPO_H
#define ORDERREPO_H

#define orderfile "data/orderfile.dat"

#include "pizza.h"
#include "topping.h"
#include "product.h"

class OrderRepo{
    public:
        OrderRepo();
        ~OrderRepo();
        void GetActiveOrders(std::ostream &os);
        void OrderRepo::AddOrder(Order &order);
        Order OrderRepo::GetOrderAt(int index);
    private:
        
};
#endif
