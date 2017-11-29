#include "commandline.h"

CommandLine::printmainmenu(){
    cout << "Main menu" << endl;
    cout << "m: Managment" << endl;
    cout << "s: Sales" << endl;
    cout << "p: preperation" << endl;
    cout << "d: Delivery" << endl;
}
// CommandLine::userinteraction(){
//     printmainmenu();
// }
void CommandLine::salesPerson(){
   cout << "e: Edit a order" << endl;
   cout << "c: Create a order" << endl;
   cout << "q: Quit" << endl;
}
char CommandLine::SalesEditor(){
    cout << "p: Print menu" << endl;
    cout << "a: Add from menu" << endl;
    cout << "r: Register order" << endl;
    cout << "d: Add a pizza" << endl; // this should be an entire process of it self, do it later
    cout << "s: Show the order in current state" << endl;
    cout << "m: mark the order as payed" << endl;
    cout << "c: Comment" << endl;
    cout << "h: Toggle pickup" << endl;
    cout << "l: Set pickup location" << endl;
    cout << "q: Quit (does not save)" << endl;
    char validInputs[] = {'p','a','r','d','s','m','c','h','q','l'};
    char input;
    cin >> input;
    for(int i = 0; i < 10; i++){
        if(input == validInputs[i]){
            return input;
        }
    }
    cout << "Invalid input!" << endl;
    cout << "Please enter one of the following: " << endl;
    return SalesEditor();
}
// char CommandLine::Preperation(){
//     cout << " " << endl;
//     cout << " " << endl;
//     cout << " " << endl;
//     char validInputs[] = {};
//     char input;
// }
// char CommandLine::Delivery(){
//     cout << " " << endl;
//     char validInputs[] = {};
//     char input;
// }
