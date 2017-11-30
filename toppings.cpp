#include "toppings.h"

Toppings::Toppings() {
    size = arraySize;
    toppingList = new Topping[size];
    numberOfToppings = 0;
}
Toppings::~Topping(){
    if(toppingList != NULL){
        delete [] toppingList;
        toppingList = NULL;
        numberOfToppings = 0;
    }
}
void Toppings::AddTopping(Topping tp){
    if (numberOfToppings >= size-1){
        Resize();
    }
    toppingList[numberOfToppings] = tp;
    numberOfToppings++;
}
void Toppings::Resize() {
    Toppings tmp = new Topping[size];
    for (int i=0; i< size; i++){
        tmp[i] = toppingList[i];
    }
    delete[] toppingList;
    size *= 2;
    toppingList = new Topping[size];
    for (int i=0; i< size/2; i++){
        toppingList[i] = tmp[i];
    }
    delete[] tmp;
}
friend std::ostream& operator<<(std::ostream &os, Toppings &topp){
    
}
friend std::istream& operator>>(std::istream &is, Toppings &topp);
