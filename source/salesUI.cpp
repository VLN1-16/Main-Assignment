#include "salesUI.h"

SalesUI::SalesUI(){}

void SalesUI::PrintSalesMenu(){
    Sales sales;
    cout << "a: List active orders" << endl;
    cout << "i: List inactive orders" << endl;
    cout << "e: Edit a order" << endl;
    cout << "c: Create a order" << endl;
    cout << "b: Go back" << endl;
    cout << "q: Quit" << endl;

    char userAns = 0;
    cin >> userAns;
    cout << endl;

    switch(tolower(userAns)){
        case 'a':

            sales.GetActiveOrders(cout);
            break;
        case 'i':

            sales.GetInActiveOrders(cout);
            break;
        case 'e':
            OrderEditor();
            break;
        case 'c':
            CreateOrder();
            break;
        case 'b':
            break;
        case 'q':
            cout << "Are you sure you want to quit?" << endl;
            cout << "y: yes" << endl << "n: no" << endl;
            cin >> userAns;
            if(tolower(userAns) == 'y')
                exit(EXIT_SUCCESS);
                else
                PrintSalesMenu();
                break;
        default:
            cout << "Please enter a valid input!" << endl;
            PrintSalesMenu();
            break;
    }
}

void SalesUI::OrderEditor(){
    cout << "Select order" << endl;
    Sales sales;
    int orderid;
    sales.GetActiveOrders(cout);
    cin >> orderid;
    Order order = sales.GetThisOrder(orderid-1);
    EditOrder(order);

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

}
void SalesUI::EditOrder(Order order){
    Sales sales;
    bool again = true;
    while(again){

        cout << "a: Add pizza from menu" << endl;
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
            case 'a':
            int pizzaid;
                cout << "Select a pizza: " << endl;
                sales.GetPizzas(cout);
                cin >> pizzaid;
                order.AddPizza(sales.GetPizza(pizzaid-1));
                break;
            case 'r':
                cout << "Register order.." << endl;
                break;
            case 'd':
                cout << "This should open the pizza menu for selecting pizzas.. " << endl;
                //CreatePizza();
                break;
            case 's':
                cout << "Showing order in current state!" << endl;
                cout << order << endl;
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
                PrintSalesMenu();
                break;
            case 'q':
                cout << "Are you sure you want to quit?" << endl;
                cout << "y: yes" << endl << "n: no" << endl;
                cin >> userAns;
                if(tolower(userAns) == 'y')
                    exit(EXIT_SUCCESS);
                else
                    EditOrder(order);
                break;
            default:
                cout << "Please enter a valid input!" << endl;
                EditOrder(order);
                break;
        }
        cout << "Add another item? (y/n)" << endl;
        cin >> userAns;
        if(tolower(userAns) == 'y')
            break;
        else
            again = false;
    }
}
void SalesUI::CreateOrder(){
    
    char first[lengthOfName];
    char last[lengthOfName];
    char phone[lengthOfName];
    cout << "Firstname of costumer" << endl;
    cin >> first;
    cout << "Lastname of costumer" << endl;
    cin >> last;
    cout << "phone of costumer" << endl;
    cin >> phone;
    Costumer costumer(first, last,phone);
    Order order(costumer);
    EditOrder(order);

}
