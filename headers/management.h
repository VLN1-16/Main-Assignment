#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <iostream>

static class Management{
    public:
        Management();
        ~Management();
        void AddTopping(Topping topping);
        void AddPizza(Pizza pizza);
        void AddProduct(Product product);
        <template typename T>
        void ChangePrice(T product, int newPrice);
        <template typename T>
        void ListProducts(T product);
        void AddDeliveryPlace(char name[sizeOfplace],char address[sizeOfplace],char phone[7], bool = true);
    private:
};
#endif
