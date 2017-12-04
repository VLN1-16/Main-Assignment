#include "pizza.h"

Pizza::Pizza() : Product(){
    numberOfToppings = 2;
    toppings = NULL;
    currTopping = 0;
    price  = 1000;
    offset = 1.4;
    size   = 16;
}

Pizza::Pizza(char n[sizeOfName], int Price, double Offset, int Size) {
    SetName(n);
    numberOfToppings = 2;
    toppings = new Topping[numberOfToppings];
    currTopping = 0;
    price  = Price; 
    offset = Offset;
    size   = Size;;
}
Pizza::~Pizza() {
    if(toppings != NULL){
        delete [] toppings;
    }
}

int Pizza::GetNumberOfToppings() const {
    return currTopping;
}
int Pizza::GetPrice() const{
    return price;
}
int Pizza::GetSize() const{
    return size;
}
void Pizza::resize(){
    Topping* ntopping = new Topping[numberOfToppings * 2];
    for(int i = 0; i < currTopping; i++){
        ntopping[i] = toppings[i];
    }
    delete [] toppings;
    toppings = ntopping;
    ntopping = NULL;
    numberOfToppings *= 2;
}
void Pizza::AddTopping(Topping topping, bool calcOffset, bool free){
    if(toppings ==  NULL)
        toppings = new Topping[numberOfToppings];
    if (currTopping == numberOfToppings){
        resize();
    }
    if(calcOffset)
        topping.SetPrice(std::ceil(topping.GetPrice() * offset));
    toppings[currTopping] = topping;
    currTopping++;
    if(!free)
        price += topping.GetPrice(); // costumer always looses part of a krona
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
std::istream& operator>>(std::istream &is, Pizza& pizza){
    int number = 0;
    is >> pizza.name >> pizza.price >> number;
    for(int i = 0; i < number; i++){
        Topping newtopping;
        is >> newtopping;
        pizza.AddTopping(newtopping);
    }
    return is;
}
void Pizza::WriteBin(std::ostream& BinaryOut){
    // Write inherited information on this pizza
    Product::WriteBin(BinaryOut); 
    // number of toppings 
    BinaryOut.write((char*)(&currTopping), sizeof(int));
    for(int i = 0; i < currTopping; i++){
         // Write each of the topping to the stream
        toppings[i].WriteBin(BinaryOut);
    }
}
void Pizza::ReadBin(std::istream& BinaryIn){
    // Read inherited information on this pizza
    Product::ReadBin(BinaryIn);
    int tempcurr = 0;
    BinaryIn.read((char*)(&tempcurr), sizeof(int));
    for(int i = 0; i < tempcurr; i++){
        Topping newtopping;
        newtopping.ReadBin(BinaryIn);
        AddTopping(newtopping, false, true);
    }
}
bool Pizza::operator ==(const Pizza& pizza){
    if(pizza.size != size) return false;
    if(pizza.offset != offset) return false;
    if(pizza.price != price) return false;
    if(pizza.numberOfToppings != numberOfToppings) return false;
    for(int i = 0; i < numberOfToppings; i++){
        if(!(pizza.toppings[i] == toppings[i])) return false;
    } 
    return true;
}
