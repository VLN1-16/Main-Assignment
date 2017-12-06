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
    cout << "s: Edit pizza type/size" << endl;
    cout << "t: Edit pizza toppings" << endl;
    cout << "m: Edit/add pizza on menu" << endl;
    cout << "p: Edit/add product on menu" << endl;
    cout << "e: Edit prices" << endl;
    cout << "l: Edit/add branch locations" << endl;
    cout << "a: Edit active order" << endl;
    cout << "b: Go back" << endl;
    cout << "q: Quit" << endl;

    char userAns = 0;
    cin >> userAns;
    cout << endl;
    char user = 'm';

    switch(tolower(userAns)){
        case 's':
            cout << "Options for editing pizza type/size..";
            EditSizes();
            break;
        case 't':
            cout << "Options for editing pizza toppings..";
            break;
        case 'm':
            cout << "Options for editing pizza menu..";
            break;
        case 'p':
            cout << "Options for editing products..";
            break;
        case 'e':
            editPrices();
            break;
        case 'l':
            cout << "Options for branch locations..";
            break;
        case 'a':
            salesEditor(user);
            break;
        case 'b':
            printMainMenu();
            break;
        case 'q':
            cout << "Are you sure you want to quit?" << endl;
            cout << "y: yes" << endl << "n: no" << endl;
            cin >> userAns;
            if(tolower(userAns) == 'y')
                exit(EXIT_SUCCESS);
            else
                managementView();
            break;
        default:
            cout << "Please enter a valid input!" << endl;
            managementView();
            break;
    }
}
void CommandLine::EditSizes(){
    int s;
    Management manager;
    cout << "enter size ";
    cin >> s;
    manager.AddPizzaSize(s);
    manager.GetPizzaSizes(cout);
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
   cout << "e: Edit a order" << endl;
   cout << "c: Create a order" << endl;
   cout << "b: Go back" << endl;
   cout << "q: Quit" << endl;

   char userAns = 0;
   cin >> userAns;
   cout << endl;
   char user = userAns; //lets salesEditor function to detect Management or Salesperson

   switch(tolower(userAns)){
        case 'e':
            cout << "Enter costumer name or phone number: " << endl;
            cout << "When name or phonenumber is found, " << endl;
            cout << "this should direct salesPerson to salesEditor for this order." << endl;
            salesEditor(user);
            break;
        case 'c':
            cout << "Select items to add to basket: " << endl;
            break;
        case 'b':
            printMainMenu();
            break;
        case 'q':
            cout << "Are you sure you want to quit?" << endl;
            cout << "y: yes" << endl << "n: no" << endl;
            cin >> userAns;
            if(tolower(userAns) == 'y')
                exit(EXIT_SUCCESS);
            else
                salesPerson();
            break;
        default:
            cout << "Please enter a valid input!" << endl;
            salesPerson();
            break;
   }
}
char CommandLine::salesEditor(char user){
    cout << "p: Print menu" << endl;
    cout << "a: Add from menu" << endl;
    cout << "r: Register order" << endl;
    cout << "d: Add a pizza" << endl; // this should be an entire process of it self, do it later
    cout << "s: Show the order in current state" << endl;
    cout << "m: Mark the order as paid" << endl;
    cout << "c: Comment" << endl;
    cout << "h: Toggle pickup" << endl;
    cout << "l: Set pickup location" << endl;
    cout << "b: Go back" << endl;
    cout << "q: Quit (does not save)" << endl;

    char userAns = 0;
    cin >> userAns;
    cout << endl;
     switch(tolower(userAns)){
        case 'p':
            cout << "Prints menu-item's order number and name" << endl;
            break;
        case 'a':
            cout << "Write item number to add item to order: " << endl;
            break;
        case 'r':
            cout << "Register order.." << endl;
            break;
        case 'd':
            cout << "This should open the pizza menu for selecting pizzas.. " << endl;
            break;
        case 's':
            cout << "Showing order in current state!" << endl;
            break;
        case 'm':
            cout << "Marking pizza as paid for" << endl;
            break;
        case 'c':
            cout << "Adding a comment to order!" << endl;
            break;
        case 'h':
            cout << "Toggle pickup..." << endl;
            break;
        case 'l':
            cout << "Select a pickup location for this order" << endl;
            break;
        case 'b':
            if(user == 'e')
                salesPerson();
            else if(user == 'm')
                managementView();
            else
                cout << "Something went wrong, redirecting to Main Menu..." << endl;
                printMainMenu();
            break;
        case 'q':
            cout << "Are you sure you want to quit?" << endl;
            cout << "y: yes" << endl << "n: no" << endl;
            cin >> userAns;
            if(tolower(userAns) == 'y')
                exit(EXIT_SUCCESS);
            else
                salesEditor(userAns);
            break;
        default:
            cout << "Please enter a valid input!" << endl;
            salesEditor(user);
            break;
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
    return 'a';
}

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
