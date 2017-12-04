#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <iostream>
#include "filehandler.h"
#include "pizza.h"
#include "topping.h"
#include "product.h"
#include "place.h"
#include "pizzasize.h"

class Management{
    public:
        Management();
        ~Management();
        void AddTopping(Topping topping);
        void AddPizza(Pizza pizza);
        void AddProduct(Product product);
        void GetPizzaSizes(std::ostream &os);
        void AddPizzaSize(Pizzasize s);
        void ChangePrice(int newPrice);

        // void ChangePrice(T product, int newPrice);

        // void ListProducts(T product);
        void AddDeliveryPlace(Place place);
    private:
};
#endif
