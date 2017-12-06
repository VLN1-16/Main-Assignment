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
        void AddPizza(Pizza& pizza);
        void AddProduct(Product product);
        void GetPizzaSizes(std::ostream &os);
        void GetPizzas(std::ostream &os);
        void GetToppings(std::ostream &os);
        void GetProducts(std::ostream &os);
        void RemoveProduct(int index);
        void AddPizzaSize(Pizzasize s);
        void ChangePrice(int newPrice);
        void RemoveTopping(int index);
        void DeletePizzaSizeat(int index);
        void AddPlace(Place p);
        void GetPlaces(std::ostream& os);
        void RemovePlace(int index);
        Pizzasize GetPizzaSizeat(int index);
        Topping GetToppingat(int index);
        // void ChangePrice(T product, int newPrice);

        // void ListProducts(T product);
        void AddDeliveryPlace(Place place);
    private:
};
#endif
