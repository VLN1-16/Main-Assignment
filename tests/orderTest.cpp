#include <iostream>
#include <cassert>
#include <sstream>
#include "product.h"
#include "pizza.h"
#include "topping.h"
#include "costumer.h"
#include "order.h"

using namespace std;

int main(){ 
    // Initialize an order to test
    Topping toppings[5] = {Topping("Brauðteningar", 123),Topping("Skinka", 231),Topping("Sveppir", 782),Topping("Pepperoni", 341),Topping("Hvítlauksolía", 50)};
    Product products[5] = {Product("Stór Kók", 500), Product("Ostagott", 600), Product("Brauðstangir", 750), Product("Medium Kók", 300),Product("Lítil Kók", 251)};
    Costumer cost("First", "Last","5812345");
    Pizza pizza("THISISNAME");
    for(int i = 0; i < 100; i++)
        pizza.AddTopping(toppings[i % 5]);
    Order ord(cost);
    // for(int i = 0; i < 100; i++)
    //     ord.AddPizza(pizza);
    
    for(int i = 0; i < 1000; i++)
        ord.AddProduct(products[i % 5]);
    // compare input and output streams // This does not make sense for order, not right now at least

    // compare binary read to binarywrite
    stringstream ss;
    ord.WriteBin(ss);
    Order ord2;
    ord2.ReadBin(ss);
    assert(ord == ord2);

    Order ord3;
    ord3 = ord; // 1
    Order* orders = new Order[5];
    for(int i = 0; i < 5; i++){
        orders[i] = ord; // 5 times
    }
    Order ord4;
    ord4 = orders[2]; // 1 time  a total of 6 times
    Order ord5 = orders[2];
    delete [] orders;
    cout << "============================================================================== Class Order looks Ok ==============================================================================" << endl;
}
