#ifndef SALESUI_H
#define SALESUI_H

#include "costumer.h"
#include "order.h"
#include "place.h"
#include "badnumber.h"
#include "iscostumernamevalid.h"

#include "pizzarepo.h"
#include "toppingrepo.h"
#include "productrepo.h"
#include "placerepo.h"
#include "pizzasizerepo.h"
#include "orderrepo.h"

#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

/*
* A user communication class,
* Get user input
* Take appropriate action
* Give a response to the user
*/

class SalesUI{
    public:
        SalesUI();
        ~SalesUI();
        //void userInteraction();
        void PrintSalesMenu();
        void OrderEditor();
        void CreateOrder();
        void EditOrder(Order order, bool edit = false, int index = 0);
        Place pickplace();
        // A sales person needs to select an order (new or old)
        // And proceed to edit that order

        // All paid orders are marked as completed and
        // are not available for sales people

        // Gives options to the sales person and returns their choice

    private:
        PizzaRepo* pizzas;
        ToppingRepo* toppings;
        ProductRepo* products;
        PlaceRepo* places;
        PizzaSizeRepo* pizzaSizes;
        OrderRepo* activeorders;
};
#endif
