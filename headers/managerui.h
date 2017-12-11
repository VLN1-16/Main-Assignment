#ifndef MANAGERUI_H
#define MANAGERUI_H

#include <iostream>
#include "management.h" // we want to get rid of this dependency
#include "filehandler.h"
#include "pizzasize.h"
#include "place.h"
#include "pizza.h"
#include "pizzarepo.h"
#include "toppingrepo.h"
#include "productrepo.h"
#include "placerepo.h"
#include "pizzasizerepo.h"

using namespace std;

class ManagerUI{
    public: 
        ManagerUI();
        ~ManagerUI();
        void ManagerMenu();
        void EditSizes();
        void EditProducts();
        void EditToppings();
        void EditLocations();

        void EditPizzas();
    private:
        Management* manager;
};

#endif
