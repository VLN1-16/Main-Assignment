#include <iostream>
#include "product.h"
using namespace std;

int main(){
    char pizza[sizeOfName];
    int verd;
    char description[sizeOfDesc];
    cout << "enter name" <<endl;
    cin >> pizza;
    cout << "enter price" <<endl;
    cin >> verd;
    cout << "enter description" <<endl;
    cin >> description;
    Product p1(verd,pizza,description);
    cout << p1 << endl;
}
