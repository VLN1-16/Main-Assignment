#ifndef SALES_H
#define SALES_H
#include <iostream>
#include "filehandler.h"
#include "pizza.h"
#include "topping.h"
#include "product.h"
#include "place.h"
#include "pizzasize.h"
#include "order.h"

class Sales{
    public:


        void AddPizzaToOrder(int oid,int pid);



        void GetPizzas(std::ostream &os);
        Pizza GetPizza(int id);
        Order GetThisOrder(int orderid);



        void CreatePizza(Order order);
        void GetActiveOrders(std::ostream &os);
        void GetInActiveOrders(std::ostream &os);

        // void ChangePrice(T product, int newPrice);

        // void ListProducts(T product);

    private:
};
#endif
