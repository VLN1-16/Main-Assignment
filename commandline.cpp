#include "commandline.h"

CommandLine::printmainmenu(){
    cout << "Main menu" << endl;
    cout << "m: Managment" << endl;
    cout << "s: Sales" << endl;
    cout << "p: preperation" << endl;
    cout << "d: Delivery" << endl;
}
CommandLine::userinteraction(){
    printmainmenu();
}
void CommandLine::saleseditorder(){ // Should be 
    
    cout << "p: Print menu" << endl;
    cout << "a: Add from menu" << endl;
    cout << "r: Register order" << endl;
    cout << "d: Add a pizza" << endl; // this should be an entire process of it self, do it later
    cout << "s: Show the order in current state" << endl;
    cout << "m: mark the order as payed" << endl;
    cout << "c: Comment" << endl;
}
