#ifndef ORDERREPO_H
#define ORDERREPO_H

#define orderfile "data/orderfile.dat"

#include "pizza.h"
#include "topping.h"
#include "product.h"
#include "order.h"
#include "filehandler.h"
#include "place.h"
#include <vector>

class OrderRepo{
    public:
        OrderRepo();
        ~OrderRepo();
        void GetActiveOrders(std::ostream &os);
        void AddOrder(Order &order);
        Order GetOrderAt(int index);
        /*
        *  Functions for getting items based on pizzas, 
        *  Used in preperation view
        */
        void GetPizzaByPlace(std::ostream& os, const int index, const Place& myplace);
        void UpdatePizzaStatus(int index, const int status, const Place& myplace);
    private:
        FileHandler<Order>* orderList;        
        void FillPizzaVector(const Place& myplace);
        std::vector<Pizza> pizzas;
};
#endif
