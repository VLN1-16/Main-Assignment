#include "commandline.h"

using namespace std;

void CommandLine::printMainMenu(){
    cout << "~Welcome to Main Menu~" << endl << endl;
    cout << "Press: " << endl;
    cout << "m: For management" << endl;
    cout << "s: For sales" << endl;
    cout << "p: For preparation" << endl;
    cout << "d: For delivery" << endl << endl;

    char userAns = 0;
    cin >> userAns;
    char user = userAns; //lets salesEditor function to detect Management or Salesperson

    switch(tolower(userAns)){
        case 'm':
            cout << "~Management~" << endl;

            managementView();
            break;
        case 's':
            //TO-DO: clear screen
            cout << "~Salesperson~" << endl;
            salesPerson();
            break;
        case 'p':
            cout << "~Preparation~" << endl;
            break;
        case 'd':
            cout << "~Delivery~" << endl;
            cout << "1. Select branch location" << endl;
            cout << "2. Get list of active orders for selected location" << endl;
            cout << "3. Get list of ready orders for selected location" << endl;
            cout << "4. Search/select desired order" << endl;

            break;
        default:
            cout << "Not a valid input!" << endl;
            printMainMenu();
            break;
    }
}

void CommandLine::managementView(){
    ManagerUI manager;
    manager.ManagerMenu();
}
void CommandLine::editPrices(){
    cout << "p: Edit prices for pizzas" << endl;
    cout << "t: Edit prices for toppings" << endl;
    cout << "d: Edit prides for products" << endl;
    cout << "b: Go back" << endl;
    cout << "q: Quit" << endl;

    char userAns = 0;
    cin >> userAns;
    cout << endl;
    int newprice = 0;
    switch(tolower(userAns)){
        case 'p':
            cout << "Editing pizza prices..." << endl;
            /*FileHandler<Pizza> list("pizzamenu.obj");
            cout << list << endl;
            cout << "Enter ID of pizza to edit and the new price" << endl;
            cin >> id >> newprice;
            management.ChangePrice(id,newprice); */
            break;
        case 't':
            cout << "Editing topping prices..." << endl;
            break;
        case 'd':
            cout << "Editing product prices..." << endl;
            break;
        case 'b':
            managementView();
            break;
        case 'q':
            cout << "Are you sure you want to quit?" << endl;
            cout << "y: yes" << endl << "n: no" << endl;
            cin >> userAns;
            if(tolower(userAns) == 'y')
                exit(EXIT_SUCCESS);
            else
                editPrices();
            break;
        default:
            cout << "Please enter a valid input!" << endl;
            editPrices();
            break;
    }
}

void CommandLine::salesPerson(){
    SalesUI salesperson;
    salesperson.PrintSalesMenu();
}

    /*char validInputs[] = {'p','a','r','d','s','m','c','h','q','l'};
    char input;
    cin >> input;
    for(int i = 0; i < 10; i++){
        if(input == validInputs[i]){
            return input;
        }
    }
    cout << "Invalid input!" << endl;
    cout << "Please enter one of the following: " << endl;
    return SalesEditor();*/

/*void CommandLine::Preparation(){
    cout << "Select location:" << endl;
    cout << "List of active locations..." << endl;

    char userAns = 0;
    cin >> userAns;
    cout << endl;

    switch(tolower(userAns)){
        case '':

    }

}
*/

CommandLine::CommandLine(){
}
CommandLine::~CommandLine(){}

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
