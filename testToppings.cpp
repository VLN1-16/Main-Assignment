#include <iostream>
#include "toppings.h"
#include "topping.h"

using namespace std;

int main(){
    Toppings list;
    int n;
     cout << list << endl;

    cout << "enter number of toppings" <<endl;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        Topping tp;
        cout << "Topping(name price): " <<endl;
        cin >> tp;
        list.AddTopping(tp);
    }

    return 0;
}
