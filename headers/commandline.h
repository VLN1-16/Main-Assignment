#ifndef COMMANDLINE_H
#define COMMANDLINE_H
#include <iostream>
#include "managerui.h"
#include "salesUI.h"
#include "preperationUI.h"
#include "place.h"
#include "placerepo.h"
using namespace std;

/*
* A user communication class,
* Get user input
* Take appropriate action
* Give a response to the user
*/

/*
* We have four user types, each has a different interface
* Management :
* Sales :
* Preparation :
* Delivery :
*/
class CommandLine{
    public:
        CommandLine();
        ~CommandLine();

        //void userInteraction();
        void printMainMenu();
        // A sales person needs to select an order (new or old)
        // And proceed to edit that order

        // All paid orders are marked as completed and
        // are not available for sales people

        // Gives options to the sales person and returns their choice

        void managementView();
        void salesPerson();
        void preperationView(Place place);
        Place pickplace();
    private:
        PlaceRepo* places;

};
#endif
