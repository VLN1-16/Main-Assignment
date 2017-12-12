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
        void GetActiveOrders(std::ostream &os,const Place& myplace);
        void GetReadyOrders(std::ostream &os,const Place& myplace);
        void ReadOrderAt(std::ostream &os,int index);
        void AddOrder(Order &order);
        Order GetOrderAt(int index);
        /*
        *  Functions for getting items based on pizzas,
        *  Used in preperation view
        */
        void MarkPaid(int index);
        void RemoveOrder(int index);
        void GetPizzaByPlace(std::ostream& os, const int index, const Place& myplace);
        void UpdatePizzaStatus(int index, const int status, const Place& myplace);
    private:
        FileHandler<Order>* orderList;
        void FillPizzaVector(const Place& myplace);
        std::vector<Pizza> pizzas;
};
#endif