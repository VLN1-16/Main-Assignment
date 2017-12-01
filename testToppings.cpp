#include <iostream>
#include "filehandler.h"
#include "topping.h"
#include "place.h"


using namespace std;

int main(){

    int n;
/*
    FileHandler<Topping> list("pizzatoppings.obj");

     cout << list << endl;

    cout << "enter number of toppings" <<endl;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        Topping tp;
        cout << "Topping(name price): " <<endl;
        cin >> tp;
        list.AddProduct(tp);
    }
    list.RemoveProduct(3);
    cout << list << endl;
    // product
    FileHandler<Product> list2("products.obj");

     cout << list2 << endl;

    cout << "enter number of products" <<endl;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        Product tp;
        cout << "Product(name price): " <<endl;
        cin >> tp;
        list2.AddProduct(tp);
    }
*/
    FileHandler<Place> list3("Pizzaplaces.obj");

     cout << list3 << endl;

    cout << "enter number of places" <<endl;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        Place p;
        cout << "Pizzaplace(name address phone): " <<endl;
        cin >> p;
        list3.AddProduct(p);
    }
     cout << list3 << endl;
    //list3.RemoveProduct(3);
     cout << list3 << endl;
    return 0;
}
