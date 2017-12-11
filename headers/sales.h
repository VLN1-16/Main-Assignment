#ifndef SALES_H
#define SALES_H

#define orderfile "data/orderfile.dat"
#define inActiveOrderListfile "data/inactiveorders.dat"
#define pizzafile "data/pizzamenu.dat"
#define productfile "data/products.dat"
#define toppingfile "data/toppings.dat"
#define pizzasizefile "data/pizzasizes.dat"
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
        Pizzasize GetPizzaSize(int index);
        
        void GetPizzas(std::ostream &os);
        Pizza GetPizza(int id);
        Order GetThisOrder(int orderid);
        void AddOrder(Order &order);

        void CreatePizza(Order order);
        void GetActiveOrders(std::ostream &os);
        void GetInActiveOrders(std::ostream &os);
        
        void GetProducts(std::ostream& os);
        Product GetProduct(int index);
        
        void GetToppings(std::ostream& os);
        Topping GetTopping(int index);

        void AddDeliveryPlace(Place place);
    private:
        FileHandler<Order>* orderList;
        FileHandler<Order>* inActiveOrderList;
        FileHandler<Pizza>* pizzamenu;
        FileHandler<Product>* productList;
        FileHandler<Topping>* toppingList;
        FileHandler<Pizzasize>* pizzasizes;
        
};
#endif
