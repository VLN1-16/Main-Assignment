#ifndef COMMANDLINE_H
#define COMMANDLINE_H
#include <iostream> 
/*
* An user communication class,
* Get user input
* Take appropriate action
* Give a response to the user
*/

/*
* We have four user types, each has a diffrent interface
* Managment :  
* Sales : 
* Preperation :
* Delivery : 
*/
class CommandLine{
    public:
        CommandLine();
        ~CommandLine();
        void printMainMenu();
        // A sales person needs to select an order (new or old)
        // And proceed to edit that order

        // All paid orders are marked as completed and
        // are not available for sales people 

        // Gives options to the sales person and returns their choice
        void SalesEditor();
    private:
};
#endif
