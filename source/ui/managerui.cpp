#include "managerui.h"

ManagerUI::ManagerUI() {
    pizzas = new PizzaRepo();
    toppings = new ToppingRepo();
    products = new ProductRepo();
    places   = new PlaceRepo();
    pizzaSizes = new PizzaSizeRepo();
    inorders = new InActiveOrderRepo();
}
ManagerUI::~ManagerUI(){
    delete pizzaSizes;
    delete pizzas;
    delete toppings;
    delete products;
    delete places;
}
void ManagerUI::ManagerMenu(){
    while(true){
        cout << "s: Edit pizza type/size" << endl; // DONE
        cout << "t: Edit pizza toppings" << endl; // DONE
        cout << "m: Edit/add pizza on menu" << endl; // NOT DONE
        cout << "p: Edit/add product on menu" << endl; // DONE
        cout << "l: Edit/add branch locations" << endl; // ALMOST DONE

        // cout << "a: Edit active order" << endl; // NOT DONE
        cout << "w: Print closed orders" << endl; // NOT DONE

        cout << "b: Go back" << endl;
        cout << "q: Quit" << endl;

        char userAns = 0;
        cin >> userAns;
        cout << endl;

        switch(tolower(userAns)){
            case 's':
                EditSizes();
                break;
            case 't':
                EditToppings();
                break;
            case 'm':
                EditPizzas();
                break;
            case 'p':
                EditProducts();
                break;
            case 'l':
                EditLocations();
                break;
            case 'a':
                // salesEditor(user);
                break;
            case 'b':
                return;
            case 'w':
                if(inorders->GetNumberOfOrders() == 0){
                    cout << "No inactive orders" << endl;
                }
                inorders->GetOrders(cout);
                break;
            case 'q':
                cout << "Are you sure you want to quit?" << endl;
                cout << "y: yes" << endl << "n: no" << endl;
                cin >> userAns;
                if(tolower(userAns) == 'y')
                    exit(0);
                break;
            default:
                cout << "Please enter a valid input!" << endl;
                break;
        }
    }
}

void ManagerUI::EditSizes(){
    while(true){
        cout << "Editing pizza bases : " << endl;
        cout << "a: Add a pizza bottom" << endl;
        cout << "d: Delete a pizza bottom" << endl;
        cout << "l: List all current bottoms" << endl;
        cout << "b: Back" << endl;
        cout << "q: Quit" << endl;
        char userAns = 0;
        cin >> userAns;
        cout << endl;

        switch(tolower(userAns)){
            case 'a':{
                int s;
                double offset;
                int price;
                cout << "What size would you like for the pizza : ";
                cin >> s;
                cout << "What would be the price of this pizza : ";
                cin >> price;
                cout << "What precentage offset should there be ageins topping base price (1 for same, 1.2 for 20% more): ";
                cin >> offset;
                Pizzasize newbase(s, offset, price);
                pizzaSizes->AddPizzaSize(newbase);
                break;
            }
            case 'd':{
                pizzaSizes->GetPizzaSizes(cout);
                cout << "Which base number would you like to delete : " << endl;
                int base;
                cin >> base;
                try{
                    pizzaSizes->DeletePizzaSizeat(base - 1);
                }catch(IndexOutOfRangeException e){
                    cout << "Invalid input" << endl;
                    cin.clear();
                    cin.ignore(80, '\n');
                }
                break;
            }
            case 'l':{
                if(pizzaSizes->GetNumberOfPizzaSizes() == 0){
                    cout << "No Pizza bottoms" << endl;
                }
                pizzaSizes->GetPizzaSizes(cout);
                break;
            }
            case 'b':
                     return;
            case 'q':
                     exit(0);
            default:
                cout << "Please eneter a valid input!" << endl;
                break;
        }
    }
}
void ManagerUI::EditProducts(){
    while(true){
        cout << "Editing products : " << endl;
        cout << "a: Add a product" << endl;
        cout << "d: Delete a product" << endl;
        cout << "l: List all products" << endl;
        cout << "b: Back" << endl;
        cout << "q: Quit" << endl;
        char userAns = 0;
        cin >> userAns;
        cout << endl;

        switch(tolower(userAns)){
            case 'a':{
                char name[lengthOfName];
                int price;
                cout << "What is the name of the product : ";
                cin >> name;
                cout << "What is the price : ";
                cin >> price;
                Product prod(name, price);
                products->AddProduct(prod);
                break;
            }
            case 'd':{
                products->GetProducts(cout);
                int index;
                cout << "Product number what would you like to remove : ";
                cin >> index;
                try{
                    products->RemoveProduct(index - 1);
                }catch(IndexOutOfRangeException e){
                    cout << "Invalid input!" << endl;
                    cin.clear();
                    cin.ignore(80, '\n');
                }
                break;
            }
            case 'l':
                if(products->GetNumberOfProducts() == 0){
                    cout << "There are no products" << endl;
                    break;
                }
                products->GetProducts(cout);
                break;
            case 'b':
                return;
                break;
            case 'q':
                exit(0);
                break;
        }
    }
}
void ManagerUI::EditToppings(){
    while(true){
        cout << "Editing toppings : " << endl;
        cout << "a: Add a topping" << endl;
        cout << "d: Delete a topping" << endl;
        cout << "l: List all toppings" << endl;
        cout << "b: Back" << endl;
        cout << "q: Quit" << endl;
        char userAns = 0;
        cin >> userAns;
        cout << endl;

        switch(tolower(userAns)){
            case 'a':{
                cin.clear();
                cin.ignore(80, '\n');
                string name;
                int price;
                cout << "What is the name of the topping : ";
                getline(cin, name);
                cout << "What is the price : ";
                cin >> price;
                Topping top(name, price);
                toppings->AddTopping(top);
                break;
            }
            case 'd':{
                toppings->GetToppings(cout);
                int index;
                cout << "Topping number what would you like to remove : ";
                cin >> index;
                try{
                    toppings->RemoveTopping(index - 1);
                }catch(IndexOutOfRangeException e){
                    cout << "Invalid input!" << endl;
                    cin.clear();
                    cin.ignore(80, '\n');
                }
                break;
            }
            case 'l':
                if(toppings->GetNumberOfToppings() == 0){
                    cout << "There are no toppings" << endl;
                    break;
                }
                toppings->GetToppings(cout);
                break;
            case 'b':
                return;
                break;
            case 'q':
                exit(0);
                break;
            default:
                cout << "Invalid input!" << endl;
        }
    }
}
void ManagerUI::EditLocations(){
    while(true){
        cout << "Editing Locations : " << endl;
        cout << "a: Add a Location" << endl;
        cout << "d: Delete a place" << endl;
        cout << "l: List all locations" << endl;
        cout << "b: Back" << endl;
        cout << "q: Quit" << endl;
        char userAns = 0;
        cin >> userAns;
        cout << endl;

        switch(tolower(userAns)){
            case 'a':{
                string name;
                string address;
                char phone[sizeOfplace];
                cout << "What is the name of this place : ";
                cin.clear();
                cin.ignore(80, '\n');
                getline(cin, name);
                cout << "What is the address of this place : ";
                getline(cin, address);
                cout << "What is the phone number : ";
                cin >> phone;
                Place p(name, address, phone);
                try{
                    places->AddPlace(p);
                }
                catch(BadNumber e){
                    cout << "The phone number was invalid!" << endl;
                    cin.clear();
                    cin.ignore(80, '\n');
                }
                break;
            }
            case 'd':
                if(places->GetNumberOfPlaces() == 0){
                    cout << "There are no places to delete" << endl;
                    break;
                }
                places->GetPlaces(cout);
                int index;
                cout << "Branch location Id : ";
                cin >> index;
                try{
                    places->RemovePlace(index - 1);
                }catch(IndexOutOfRangeException e){
                    cout << "Invalid input!" << endl;
                    cin.clear();
                    cin.ignore(80, '\n');
                }
                break;
            case 'l':
                if(places->GetNumberOfPlaces() == 0){
                    cout << "No places" << endl;
                    break;
                }
                places->GetPlaces(cout);
                break;
            case 'b':
                return;
            case 'q':
                exit(0);
            default:
                cout << "Invalid input!" << endl;
        }
    }
}
void ManagerUI::EditPizzas(){
    while(true){
        cout << "Editing Ready pizzas : " << endl;
        cout << "a: Add a pizza" << endl;
        cout << "d: Delete a pizza" << endl;
        cout << "l: List all pizzas" << endl;
        // cout << "e: edit a pizza" << endl;
        cout << "b: Back" << endl;
        cout << "q: Quit" << endl;

        char userAns = 0;
        cin >> userAns;
        cout << endl;

        switch(tolower(userAns)){
            case 'a':{
                while(true){
                    std::string name;
                    cout << "What is the name of the pizza : ";
                    cin.clear();
                    cin.ignore(80, '\n');
                    getline(cin, name);

                    pizzaSizes->GetPizzaSizes(cout);
                    cout << "What size do you want : ";
                    int index;
                    cin >> index;
                    try{
                        Pizzasize size = pizzaSizes->GetPizzaSizeat(index - 1);
                        Pizza pizza(name, size);
                        if(toppings->GetNumberOfToppings() == 0){
                            cout << "There are no toppings to add" << endl;
                            cout << "Unable to make a pizza" << endl;
                            break;
                        }
                        while(true){
                            cout << "Do you want to add a topping (y/n) : ";
                            char ans;
                            cin >> ans;
                            if(ans != 'y') break;
                            toppings->GetToppings(cout);
                            cout << "Which topping would you like : ";
                            cin >> index;
                            try{
                                Topping top = toppings->GetToppingat(index - 1);
                                pizza.AddTopping(top);
                            }catch(IndexOutOfRangeException e){
                                cout << "Invalid input!" << endl;
                                cin.clear();
                                cin.ignore(80, '\n');
                                cout << endl;
                            }
                        }
                        pizzas->AddPizza(pizza);
                        break;
                    }catch(IndexOutOfRangeException){
                        cout << "Invalid input!" << endl;
                    }
                }
                break;
            }
            case 'd':{
                cout << "Deleting a pizza from menu" << endl;
                if(pizzas->GetNumberOfPizzas() > 0){
                    pizzas->GetPizzas(cout);
                    int index;
                    cout << "Enter PizzaId : ";
                    cin >> index;
                    try{
                        pizzas->RemovePizza(index - 1); 
                    }catch(IndexOutOfRangeException e){
                        cout << "Invalid input!" << endl;
                        cin.clear();
                        cin.ignore(80, '\n');
                        cout << endl;
                    }
                }else{
                    cout << "There are no pizzas to delete" << endl;
                }
                break;
            }
            case 'l':
                if(pizzas->GetNumberOfPizzas() == 0){
                    cout << "There are no pizzas" << endl;
                    break;
                }
                pizzas->GetPizzas(cout);
                break;
            case 'b':{
                return;
                break;
            }
            case 'q':{
                exit(0);
                break;
            }
            default:
                     cout << "Invalid input!" << endl;
        }
    }
}
