#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#define placefile "data/places.dat"
#define toppingfile "data/toppings.dat"
#define pizzafile "data/pizzamenu.dat"
#define productfile "data/products.dat"
#define pizzasizefile "data/pizzasizes.dat"
#define inactiveorderfile "data/inactiveorders.dat"
#include <iostream>
#include "filehandler.h"
#include "pizza.h"
#include "topping.h"
#include "product.h"
#include "place.h"
#include "pizzasize.h"
#include "order.h"

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
        Place GetPlace(int index);
        void PrintOldOrders(std::ostream &os);
        Pizzasize GetPizzaSizeat(int index);
        Topping GetToppingat(int index);
        // void ChangePrice(T product, int newPrice);

        // void ListProducts(T product);
        void AddDeliveryPlace(Place place);
    private:
        FileHandler<Product>* productlist;
        FileHandler<Pizza>* pizzamenu;
        FileHandler<Topping>* toppinglist;
        FileHandler<Place>* placelist;
        FileHandler<Pizzasize>* pizzasizelist;
        FileHandler<Order>* orderlist;
};
#endif
