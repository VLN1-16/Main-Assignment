#ifndef ORDER_H
#define ORDER_H
#define sixeOfProduct 10

#include <iostream>
/*
* Each order has some products, maybe a costumer name 
* A delivery place, if it is delivered or picked up
* A timestamp on when they were created ( unixtime stamp ?, good enough).
*/
class Order{
    public:
        Order();
        ~Order();

    private:
        Product products[sizeOfProduct]; 
        Costumer costumer;
        Shop shop;
        bool pickup;
        long timestamp;
}
#endif
