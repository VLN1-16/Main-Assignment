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
    char userAns;
    while(true){
        cout << "a: List active orders" << endl;
        cout << "e: Edit a order" << endl;
        cout << "c: Create a order" << endl;
        cout << "b: Back" << endl;
        cout << "q: Quit" << endl;

        cin >> userAns;
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
    }
}
void SalesUI::OrderEditor(){
    cout << "Select an order to edit" << endl;
    int orderid;
    // check if there are any orders to edit
    if(activeorders->GetNumberOfOrders() == 0){
        cout << "There are no orders to edit" << endl;
        return;
    }
    while(true){
        try{
            activeorders->GetActiveOrders(cout);
            cout << "Order id: " << endl;
            cin >> orderid;
            Order order = activeorders->GetOrderAt(orderid-1);
            EditOrder(order, true, orderid - 1);
            return;
        }catch(IndexOutOfRangeException e){
            cout << "Please select a id that exists" << endl;
            cin.clear();
            cin.ignore(80, '\n');
            cout << endl;
        }
    }
}
void SalesUI::EditOrder(Order order, bool edit, int index){
    char userAns;
    while(true){
        cout << "a: Add pizza from menu" << endl;
        cout << "k: Add a product" << endl;
        cout << "r: Register order" << endl;
        cout << "d: Add a pizza" << endl;
        cout << "s: Show the order in current state" << endl;
        cout << "m: Mark the order as paid" << endl;
        cout << "c: Add a comment to the order" << endl;
        cout << "h: Home Delivered" << endl;
        // cout << "l: change preperation location" << endl;
        cout << "z: Add a discount to the order" << endl;
        cout << "b: Go back" << endl;
        cout << "q: Quit (does not save)" << endl;

        cin >> userAns;
        cout << endl;
        switch(tolower(userAns)){
            case 'a':
                int pizzaid;
                cout << "Select a pizza: " << endl;
                try{
                    pizzas->GetPizzas(cout);
                    cout << "PizzaId : "; 
                    cin >> pizzaid;
                    order.AddPizza(pizzas->GetPizza(pizzaid-1));
                }catch(IndexOutOfRangeException e){
                    cout << "Invalid input!" << endl;
                    cin.clear();
                    cin.ignore(80, '\n');
                }
                break;
            case 'k':{
                int productId;
                products->GetProducts(cout);
                cout << "ProductId : ";
                cin >> productId;
                Product tobeadded;
                try{
                    Product tobeadded = products->GetProduct(productId -1);
                    order.AddProduct(tobeadded);
                    break;
                }catch(IndexOutOfRangeException e){
                    cout << "Invalid input!" << endl;
                    cin.clear();
                    cin.ignore(80, '\n');
                }
                break;
            }
            case 'r':
                cout << "Registering Order" << endl;
                if(edit){
                    activeorders->EditOrder(index, order);
                }
                else{
                    activeorders->AddOrder(order);
                }
                return;
            case 'd':{

                cout << "Creating your own pizza" << endl;
                pizzaSizes->GetPizzaSizes(cout);
                cout << "What size would you like : ";

                int index;
                cin >> index;
                try{
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
                }catch(IndexOutOfRangeException e){
                    cout << "Invalid input!" << endl;
                    cin.clear();
                    cin.ignore(80, '\n');
                }
                break;
            }
            case 's':
                cout << "Showing order in current state!" << endl;
                cout << order << endl;
                break;
            case 'm':
                cout << "Marking pizza as paid for" << endl;
                order.SetPaid();
                break;
            case 'c':{
                string comment;
                cout << "What do you want to add to the order? " << endl;
                cin.clear();
                cin.ignore(80, '\n');
                getline(cin, comment);
                order.AddComment(comment);
                break;
            }
            case 'h':{
                string delivered;
                cout << "Where would you like to have the order delivered? " << endl;
                cin.clear();
                cin.ignore(80, '\n');
                getline(cin, delivered);
                order.HomeDelivery(delivered);
                break;
            }
            case 'z':{
                int d;
                cout << "How much discount (0-100):" << endl;
                cin >> d;
                // Þetta ætti ekki að ske hérna, bara grípa exception
                if(d >= 0 && d < 101){
                    order.SetDiscount(d);
                }
                else{
                    cout << "Not a valid discount" << endl;
                }
                // end of block
                break;
            }
            case 'b':
                return;
            case 'q':
                cout << "Are you sure you want to quit?" << endl;
                cout << "y: yes" << endl;
                cout << "n: no" << endl;
                cin >> userAns;
                if(tolower(userAns) == 'y')
                    exit(EXIT_SUCCESS);
                break;
            default:
                cout << "Invalid input!" << endl;
                break;
        }
    }
}
void SalesUI::CreateOrder(){
    while(true){
        char first[lengthOfName];
        char last[lengthOfName];
        char phone[lengthOfName];
        cout << "Costumer information" << endl;
        cout << "Firstname : ";
        cin >> first;
        cout << "Lastname : ";
        cin >> last;
        cout << "Phonenumber : ";
        cin >> phone;
        cout << std::endl;
        try{
            Costumer costumer(first, last, phone);
            Order order(costumer);
            Place tobeadded = pickplace();
            order.SetBranchLoc(tobeadded);
            EditOrder(order);
            return;
        }
        catch(BadNumber e){
            cout << "Exception was thrown with error: " << e.getMessage() << endl;
            cin.clear();
            cin.ignore(80, '\n');
        }
    }
}
Place SalesUI::pickplace(){
    while(true){
        int index;
        places->GetPlaces(cout);
        cout << "Where is the order suppose to be made : ";
        cin >> index;
        try{
            return places->GetPlace(index - 1);
        }
        catch(IndexOutOfRangeException e){
            cout << "Please select a place that exists ";
            cin.clear();
            cin.ignore(80, '\n');
        }
    }
}
