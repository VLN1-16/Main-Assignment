#include "salesUI.h"

SalesUI::SalesUI(){}

void SalesUI::PrintSalesMenu(){
    Sales sales;
    cout << "a: List active orders" << endl;
    cout << "i: List inactive orders" << endl;
    cout << "e: Edit a order" << endl;
    cout << "c: Create a order" << endl;
    cout << "b: Back" << endl;
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
            return;
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
    PrintSalesMenu();
}
void SalesUI::OrderEditor(){
    cout << "Select an order to edit" << endl;
    Sales sales;
    int orderid;
    sales.GetActiveOrders(cout);
    cin >> orderid;
    Order order = sales.GetThisOrder(orderid-1);
    EditOrder(order);
}
void SalesUI::EditOrder(Order order){
    Sales sales;

    while(true){

        cout << "a: Add pizza from menu" << endl;
        cout << "k: Add a product" << endl;
        cout << "r: Register order" << endl;
        cout << "d: Add a pizza" << endl;
        cout << "s: Show the order in current state" << endl;
        cout << "m: Mark the order as paid" << endl;
        // cout << "c: Comment" << endl;
        cout << "h: Toggle pickup" << endl;
        // cout << "l: change preperation location" << endl;
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
                cout << "Which number of pizza would you like : " << endl;
                cin >> pizzaid;
                order.AddPizza(sales.GetPizza(pizzaid-1));
                break;
            case 'k':{
                int productId;
                sales.GetProducts(cout);
                cin >> productId;
                Product tobeadded;
                tobeadded = sales.GetProduct(productId -1);
                order.AddProduct(tobeadded);
                break;
            }
            case 'r':
                cout << "Registering Order" << endl;
                sales.AddOrder(order);
                return;
            case 'd':{
                cout << "Creating your own pizza" << endl;
                sales.GetPizzaSizes(cout);
                cout << "What size would you like : ";
                int index;
                cin >> index;
                Pizzasize size = sales.GetPizzaSize(index - 1);
                Pizza pizza("User created", size);
                while(true){
                    cout << "Add a topping (y/n)" << endl;
                    char userans;
                    cin >> userans;
                    if(tolower(userans) != 'y') break;
                    sales.GetToppings(cout);
                    cout << "Which topping would you like : ";
                    cin >> index;
                    Topping top = sales.GetTopping(index - 1);
                    pizza.AddTopping(top);
                }
                order.AddPizza(pizza);
                break;
            }
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
    Place tobeadded = pickplace();
    order.SetBranchLoc(tobeadded);
    EditOrder(order);

}
Place SalesUI::pickplace(){
    // User has to pick his location
    int index;
    Management manager;
    manager.GetPlaces(cout);
    cout << "Where is the order suppose to be made : ";
    cin >> index;
    return manager.GetPlace(index - 1);
}
