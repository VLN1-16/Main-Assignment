#include "pizza.h"



Pizza::Pizza() : Product(){
    numberOfToppings = 0;
    toppings = 0;
    currTopping = 0;
}

Pizza::Pizza(char n[sizeOfName], int topping) {
    SetName(n);
    numberOfToppings = topping;
    toppings = new Topping[numberOfToppings];
    currTopping = 0;
    price = 1000 + 200 * numberOfToppings;
}
Pizza::~Pizza() {
    if (toppings != 0){
        delete[] toppings;
        toppings = 0;
    }
}

int Pizza::GetNumberOfToppings() const {
    return numberOfToppings;
}
void Pizza::AddTopping(Topping topping){
    if (currTopping < numberOfToppings){
        toppings[currTopping] = topping;
        currTopping++;
    }
}
std::ostream& operator<<(std::ostream &os,Pizza& pizza){
    os << pizza.GetName() << std::endl;
    os << pizza.GetPrice() << std::endl;
    os << pizza.GetNumberOfToppings()<< std::endl;
    for (int i=0; i< pizza.GetNumberOfToppings(); i++){
        os << pizza.toppings[i];
    }
    return os;
}
