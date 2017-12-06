#ifndef MANAGERUI_H
#define MANAGERUI_H

#include <iostream>
#include "management.h"
#include "filehandler.h"
#include "pizzasize.h"
#include "place.h"
#include "pizza.h"
using namespace std;

class ManagerUI{
    public: 
        ManagerUI();
        void ManagerMenu();
        void EditSizes();
        void EditProducts();
        void EditToppings();
        void EditLocations();
        void EditPizzas();
        // void 
    private:
};

#endif