#ifndef SALES_H
#define SALES_H

#define orderfile "data/orderfile.dat"
#define inActiveOrderListfile "data/inactiveorders.dat"
#define pizzafile "data/pizzamenu.dat"

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
        Sales();
        ~Sales();
        void AddTopping(Topping topping);
        void AddPizzaToOrder(int oid,int pid);
        void AddProduct(Product product);
        void GetPizzaSizes(std::ostream &os);
        void GetPizzas(std::ostream &os);
        Pizza GetPizza(int id);
        Order GetThisOrder(int orderid);
        void AddOrder(Order &order);

        void CreatePizza(Order order);
        void GetActiveOrders(std::ostream &os);
        void GetInActiveOrders(std::ostream &os);

        void AddDeliveryPlace(Place place);
    private:
        FileHandler<Order>* orderList;
        FileHandler<Order>* inActiveOrderList;
        FileHandler<Pizza>* pizzamenu;
        
};
#endif
