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
        Sales();
        ~Sales();
        void AddTopping(Topping topping);
        void AddPizzaToOrder(int oid,int pid);
        void AddProduct(Product product);
        void GetPizzaSizes(std::ostream &os);
        void GetPizzas(std::ostream &os);
        void GetToppings(std::ostream &os);
        void GetProducts(std::ostream &os);
        void AddPizzaSize(Pizzasize s);
        void ChangePrice(int newPrice);

        void CreatePizza(Order order);
        void GetActiveOrders(std::ostream &os);
        void GetInActiveOrders(std::ostream &os);

        // void ChangePrice(T product, int newPrice);

        // void ListProducts(T product);
        void AddDeliveryPlace(Place place);
    private:
};
#endif
