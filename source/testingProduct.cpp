#include <iostream>
#include "product.h"
#include "pizza.h"
#include "topping.h"
using namespace std;

int main(){
    char name[sizeOfName];
    int toppings;
    cout << "enter name of pizza" <<endl;
    cin >> name;
    cout << "enter number of toppings" <<endl;
    cin >> toppings;
    Pizza p1(name,toppings);
    for (int i = 0; i < toppings; i++) {

        cout << "Topping " << i + 1 <<": ";
        cin >> name;
        Topping topp(name);
        p1.AddTopping(topp);
    }
    cout << p1 << endl;
}
