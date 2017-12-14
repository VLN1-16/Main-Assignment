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
    cout << "s: Edit pizza type/size" << endl; // DONE
    cout << "t: Edit pizza toppings" << endl; // DONE
    cout << "m: Edit/add pizza on menu" << endl; // NOT DONE
    cout << "p: Edit/add product on menu" << endl; // DONE
    cout << "l: Edit/add branch locations" << endl; // ALMOST DONE

    cout << "a: Edit active order" << endl; // NOT DONE
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
            inorders->GetOrders(cout);
            break;
        case 'q':
            cout << "Are you sure you want to quit?" << endl;
            cout << "y: yes" << endl << "n: no" << endl;
            cin >> userAns;
            if(tolower(userAns) == 'y')
                exit(0);
            else
                ManagerMenu();
            break;
        default:
            cout << "Please enter a valid input!" << endl;
                ManagerMenu();
            break;
    }
    ManagerMenu();
}

void ManagerUI::EditSizes(){
        /*
        Here a manager can delete a size
        Add a size or modify a size. Let's start with add and delete
       */
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
            // Here we need more input validation
            Pizzasize newbase(s, offset, price);
            pizzaSizes->AddPizzaSize(newbase);
            break;
        }
        case 'd':{
            pizzaSizes->GetPizzaSizes(cout);
            cout << "Which base number would you like to delete : " << endl;
            int base;
            cin >> base;
            pizzaSizes->DeletePizzaSizeat(base - 1);
            break;
        }
        case 'l':{
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
    EditSizes();
}
void ManagerUI::EditProducts(){
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
            products->RemoveProduct(index - 1);
            break;
        }
        case 'l':
            products->GetProducts(cout);
            break;
        case 'b':
            return;
            break;
        case 'q':
            exit(0);
            break;
    }
    EditProducts();
}
void ManagerUI::EditToppings(){
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
            char name[lengthOfName];
            int price;
            cout << "What is the name of the topping : ";
            cin >> name;
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
            toppings->RemoveTopping(index - 1);
            break;
        }
        case 'l':
            toppings->GetToppings(cout);
            break;
        case 'b':
            return;
            break;
        case 'q':
            exit(0);
            break;
    }
    EditToppings();
}
void ManagerUI::EditLocations(){
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
            getline(cin, name);
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
            }
            break;
        }
        case 'd':
            places->GetPlaces(cout);
            int index;
            cout << "Which place would you like to Delete";
            cin >> index;
            places->RemovePlace(index - 1);
            break;
        case 'l':
            places->GetPlaces(cout);
            break;
        case 'b':
            return;
        case 'q':
            exit(0);
            break;
    }
    EditLocations();

}
void ManagerUI::EditPizzas(){
    cout << "Editing Ready pizzas : " << endl;
    cout << "a: Add a pizza" << endl;
    cout << "d: Delete a pizza" << endl;
    cout << "l: List all pizzas" << endl;
    cout << "e: edit a pizza" << endl;
    cout << "b: Back" << endl;
    cout << "q: Quit" << endl;
    char userAns = 0;
    cin >> userAns;
    cout << endl;

    switch(tolower(userAns)){
        case 'a':{
            std::string name;
            cout << "What is the name of the pizza : ";
            getline(cin, name);
            getline(cin, name);
            pizzaSizes->GetPizzaSizes(cout);
            cout << "What size do you want : ";
            int index;
            cin >> index;
            Pizzasize size = pizzaSizes->GetPizzaSizeat(index - 1);
            Pizza pizza(name, size);
            cout << "How many toppings do you want : ";
            int numberoftoppings;
            cin >> numberoftoppings;
            for(int i = 0; i < numberoftoppings; i++){
                toppings->GetToppings(cout);
                cout << "Which topping would you like : ";
                cin >> index;
                Topping top = toppings->GetToppingat(index - 1);
                pizza.AddTopping(top);
            }
            pizzas->AddPizza(pizza);
            break;
        }
        case 'd':{
            // int index;
            // cout << "Which place would you like to Deactivate";
            // cin >> index;
            break;
        }
        case 'l':
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
    }
    EditPizzas();

}
Pizza pizzaeditor(Pizza toedit){
    // Offer the user edits to the pizza
    return toedit;
}
