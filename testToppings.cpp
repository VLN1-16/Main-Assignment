#include <iostream>
#include "filehandler.h"
#include "topping.h"


using namespace std;

int main(){
    FileHandler<Topping> list("pizzatoppings.obj");
    int n;
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

    return 0;
}
