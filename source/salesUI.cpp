#include "salesUI.h"

SalesUI::SalesUI(){
    pizzas = new PizzaRepo();
    toppings = new ToppingRepo();
    products = new ProductRepo();
    places   = new PlaceRepo();
    pizzaSizes = new PizzaSizeRepo();
    activeorders = new OrderRepo();
}
SalesUI::~SalesUI(){
    delete pizzaSizes;
    delete pizzas;
    delete toppings;
    delete products;
    delete places;
    delete activeorders;
}

void SalesUI::PrintSalesMenu(){
    // Sales sales;
    cout << "a: List active orders" << endl;
    cout << "e: Edit a order" << endl;
    cout << "c: Create a order" << endl;
    cout << "b: Back" << endl;
    cout << "q: Quit" << endl;

    char userAns = 0;
    cin >> userAns;
    cout << endl;

    switch(tolower(userAns)){
        case 'a':
            activeorders->GetActiveOrders(cout);
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
    int orderid;
    activeorders->GetActiveOrders(cout);
    cin >> orderid;
    Order order = activeorders->GetOrderAt(orderid-1);
    EditOrder(order);
}
void SalesUI::EditOrder(Order order){
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
                pizzas->GetPizzas(cout);
                cout << "Which number of pizza would you like : " << endl;
                cin >> pizzaid;
                order.AddPizza(pizzas->GetPizza(pizzaid-1));
                break;
            case 'k':{
                int productId;
                products->GetProducts(cout);
                cin >> productId;
                Product tobeadded;
                tobeadded = products->GetProduct(productId -1);
                order.AddProduct(tobeadded);
                break;
            }
            case 'r':
                cout << "Registering Order" << endl;
                activeorders->AddOrder(order);
                return;
            case 'd':{
                cout << "Creating your own pizza" << endl;
                pizzaSizes->GetPizzaSizes(cout);
                cout << "What size would you like : ";
                int index;
                cin >> index;
                Pizzasize size = pizzaSizes->GetPizzaSize(index - 1);
                Pizza pizza("User created", size);
                while(true){
                    cout << "Add a topping (y/n)" << endl;
                    char userans;
                    cin >> userans;
                    if(tolower(userans) != 'y') break;
                    toppings->GetToppings(cout);
                    cout << "Which topping would you like : ";
                    cin >> index;
                    Topping top = toppings->GetTopping(index - 1);
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
    cin >> first >> '\n';
    cout << "Lastname of costumer" << endl;
    cin >> last;
    cout << "phone of costumer" << endl;
    cin >> phone;

    try{
        Costumer costumer(first, last, phone);
        Order order(costumer);
        Place tobeadded = pickplace();
        // DEBUG
        std::cout << tobeadded << std::endl;
        order.SetBranchLoc(tobeadded);
        EditOrder(order);
    }
    catch(isCostumerNameValid e){
        cout << "Exception was thrown with error: " << e.getMessage() << endl;
    }
}
Place SalesUI::pickplace(){
    // User has to pick his location
    int index;
    places->GetPlaces(cout);
    cout << "Where is the order suppose to be made : ";
    cin >> index;
    return places->GetPlace(index - 1);
}
