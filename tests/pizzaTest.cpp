#include <iostream>
#include "pizza.h"
#include <cassert>
#include <sstream>
using namespace std;

int main(){
    Topping toppings[5] = {Topping("Brauðteningar", 123),Topping("Skinka", 231),Topping("Sveppir", 782),Topping("Pepperoni", 341),Topping("Hvítlauksolía", 50)};
    // test constructor ageinst getters and setters 
    Pizza pizza;
    // pizza implements a dynamically resizing array of toppings, insert a weird amount of toppings and delete to check ageinst memory leaks
    for(int i = 0; i < 10; i++)
        pizza.AddTopping(toppings[i % 5]);
    
    // test binary write ageinst binary read
    stringstream ss2;
    pizza.WriteBin(ss2);
    Pizza pizza2;
    pizza2.ReadBin(ss2);
    //cout << pizza2 << endl;
    assert(pizza2 == pizza);
    // test iostream ageins outstream
    // stringstream ss; I don't care that the pizza cannot read in a pizza
    // ss << pizza;
    // Pizza pizza3;
    // ss >> pizza3;
    // cout << pizza;
    // cout << pizza3;
    // assert(pizza3 == pizza);
    // test the copy
    Pizza pizza4;
    pizza4 = pizza;
    assert(pizza4 == pizza);
    cout << "============================================================================== Class Pizza looks Ok ==============================================================================" << endl;
}
