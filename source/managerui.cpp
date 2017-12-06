#include "managerui.h"

ManagerUI::ManagerUI(){

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
            cout << "Options for editing pizza menu..";
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
            // Print old orders // some sort of filters, by costumer or time period
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
            Management manager;
            manager.AddPizzaSize(newbase);
            break;
        }
        case 'd':{
            Management management;
            management.GetPizzaSizes(cout);
            cout << "Which base number would you like to delete : " << endl;
            int base;
            cin >> base;
            management.DeletePizzaSizeat(base - 1);
            break;
        }
        case 'l':{
            Management management;
            management.GetPizzaSizes(cout);
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
            char name[sizeOfName];
            int price;
            cout << "What is the name of the product : ";
            cin >> name;
            cout << "What is the price : ";
            cin >> price;
            Product prod(name, price);
            Management management;
            management.AddProduct(prod);
            break;
        }
        case 'd':{
            Management management;
            management.GetProducts(cout);
            int index;
            cout << "Product number what would you like to remove : ";
            cin >> index;
            management.RemoveProduct(index - 1); 
            break;
        }
        case 'l':{
            Management management;
            management.GetProducts(cout);
            break;
        }
        case 'b':{
            return;
            break;
        }
        case 'q':{
            exit(0);
            break;
        }
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
            char name[sizeOfName];
            int price;
            cout << "What is the name of the topping : ";
            cin >> name;
            cout << "What is the price : ";
            cin >> price;
            Topping top(name, price);
            Management management;
            management.AddTopping(top);
            break;
        }
        case 'd':{
            Management management;
            management.GetToppings(cout);
            int index;
            cout << "Topping number what would you like to remove : ";
            cin >> index;
            management.RemoveTopping(index - 1); 
            break;
        }
        case 'l':{
            Management management;
            management.GetToppings(cout);
            break;
        }
        case 'b':{
            return;
            break;
        }
        case 'q':{
            exit(0);
            break;
        }
    }
    EditToppings();
}
void ManagerUI::EditLocations(){
    cout << "Editing Locations : " << endl;
    cout << "a: Add a Location" << endl;
    // cout << "d: Deactivate a place" << endl;
    cout << "l: List all locations" << endl;
    cout << "b: Back" << endl;
    cout << "q: Quit" << endl;
    char userAns = 0;
    cin >> userAns;
    cout << endl;
    
    switch(tolower(userAns)){
        case 'a':{
            char name[sizeOfplace];
            char addr[sizeOfplace];
            char phone[sizeOfplace];
            cout << "What is the name of this place : ";
            cin >> name;
            cout << "What is the address of this place : ";
            cin >> addr;
            cout << "What is the phone number : ";
            cin >> phone;
            Place p(name, addr, phone);
            Management management;
            management.AddPlace(p); 
            break;
        }
        case 'd':{
            Management management;
            management.GetPlaces(cout);
            int index;
            cout << "Which place would you like to Deactivate";
            cin >> index;
            management.RemovePlace(index - 1); 
            break;
        }
        case 'l':{
            Management management;
            management.GetPlaces(cout);
            break;
        }
        case 'b':{
            return;
            break;
        }
        case 'q':{
            exit(0);
            break;
        }
    }
    EditLocations();

}
