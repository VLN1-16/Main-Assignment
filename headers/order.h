#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include "costumer.h"
#include "pizza.h"
#include "product.h"
#include "topping.h"
/*
* Each order has some products, maybe a costumer name 
* A delivery place, if it is delivered or picked up
* A timestamp on when they were created ( unixtime stamp ?, good enough).
*/
class Order{
    public:
        Order();
        Order(Costumer cost);
        ~Order();
        int GetPrice(); 
        void AddProduct(Product newproduct);
        void AddPizza(Pizza newpizza);

        template <class T>
        T* resize(T* oldarray, int& cap){
            T* newarray = new T[cap * 2];
            for(int i = 0; i < cap; i++){
                newarray[i] = oldarray[i];
            }
            delete [] oldarray;
            oldarray = newarray;
            cap *= 2;
            newarray = NULL;
            return oldarray;
        }

        friend std::ostream& operator <<(std::ostream& out, Order& order);

        void WriteBin(std::ostream& out);
        void ReadBin(std::istream& is);

    private:

        int price;
        Costumer costumer;
        bool pickup;
        long timestamp;
        int discount;
        int numberOfProducts;
        int numberOfPizzas;
        int pizzacap;
        int productcap;
        bool ready;
        Pizza* pizzas;
        Product* products;
};
#endif
