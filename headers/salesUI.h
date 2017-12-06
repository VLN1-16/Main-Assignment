#ifndef SALESUI_H
#define SALESUI_H
#include <iostream>
#include <stdlib.h>
#include <cctype>
#include "sales.h"
#include "costumer.h"
#include "order.h"



/*
* A user communication class,
* Get user input
* Take appropriate action
* Give a response to the user
*/

class SalesUI{
    public:
        SalesUI();

        //void userInteraction();
        void PrintSalesMenu();
        void OrderEditor();
        void CreateOrder();
        // A sales person needs to select an order (new or old)
        // And proceed to edit that order

        // All paid orders are marked as completed and
        // are not available for sales people

        // Gives options to the sales person and returns their choice



    private:

};
#endif
