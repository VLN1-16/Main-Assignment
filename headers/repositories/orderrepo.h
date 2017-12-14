#ifndef ORDERREPO_H
#define ORDERREPO_H

#include "config.h"
#include "pizza.h"
#include "topping.h"
#include "product.h"
#include "order.h"
#include "filehandler.h"
#include "place.h"
#include "exceptions.h"

#include <vector>

class OrderRepo{
    public:
        OrderRepo();
        ~OrderRepo();
        void GetActiveOrders(std::ostream &os);
        void GetActiveOrders(std::ostream &os,const Place& myplace);
        void GetOrdersByCostumer(std::ostream &os, const Place& myplace, char phone[8]);
        void GetReadyOrders(std::ostream &os,const Place& myplace);
        void ReadOrderAt(std::ostream &os,int index,const Place& myplace);
        void AddOrder(Order &order);
        Order GetOrderAt(int index);
        /*
        *  Functions for getting items based on pizzas,
        *  Used in preperation view
        */
        void MarkPaid(int index,const Place& myplace);
        void RemoveOrder(int index, const Place& myplace);
        void GetPizzaByPlace(std::ostream& os, const unsigned int index, const Place& myplace);
        void UpdatePizzaStatus(const unsigned int index, const int status, const Place& myplace);
        const int GetNumberOfPizzas();
        const int GetNumberOfOrders();
        const int GetNumberOfOrders(const Place& myplace);
        const int GetNumberOfReadyOrders(const Place& myplace);
        void EditOrder(int index, const Order& order);
        void PreperationList(std::ostream &os,const Place& myplace,int ind);
    private:
        FileHandler<Order>* orderList;
        void FillPizzaVector(const Place& myplace);
        std::vector<pair<Pizza,std::string>> pizzas;
        void printasingleorder(ostream& os, Order ord, const int numberof);
};
#endif
