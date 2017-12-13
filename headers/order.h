#ifndef ORDER_H
#define ORDER_H

#include "costumer.h"
#include "pizza.h"
#include "product.h"
#include "topping.h"
#include "place.h"
#include "exceptions.h"
#include "config.h"

#include <iostream>
#include <string>
#include <ctime> // for the unix timestamp

class Order{
    public:
        Order();
        Order(Costumer cost);
        Order(const Order& from);
        ~Order();
        int GetPrice();
        bool IsReady();
        void SetReady();
        bool IsPaid();
        void SetPaid();
        void AddProduct(Product& newproduct);
        void AddPizza(const Pizza& newpizza);

        friend std::istream& operator >>(std::istream& is, Order& order);
        friend std::ostream& operator <<(std::ostream& out, Order& order);
        bool operator ==(Order& cmp);
        Order& operator=(const Order& order);

        void WriteBin(std::ostream& out);
        void ReadBin(std::istream& is);

        void SetBranchLoc(Place& newplace);
        Place GetBranchLoc();
        Costumer GetCostumer();

        Pizza GetPizzaat(int index);

        int GetNumberOfPizzas();
        void UpdatePizzaStatus(int index, int status);
        void HomeDelivery(std::string address);
        void AddComment(std::string comment);
    private:
        template <typename T>
        T* resize(T* oldarray, int& cap){
            T* newarray = new T[cap * 2];
            for(int i = 0; i < cap; i++){
                newarray[i] = oldarray[i];
            }
            delete [] oldarray;
            oldarray = newarray;
            cap *= 2;
            newarray = nullptr;
            return oldarray;
        }
        bool pickup;
        long timestamp;
        bool ready;
        bool paid;

        int price;
        int discount;

        Pizza* pizzas;
        int numberOfPizzas;
        int pizzacap;

        Product* products;
        int productcap;
        int numberOfProducts;

        Costumer costumer;
        Place BranchLoc;
        char address[sizeOfplace];
        char comment[sizeOfComment];
};
#endif
