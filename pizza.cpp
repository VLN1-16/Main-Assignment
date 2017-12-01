#include "pizza.h"

Pizza::Pizza() : Product(){
    numberOfToppings = 2;
    toppings = new Topping[numberOfToppings];
    currTopping = 0;
    price  = 1000; // base price, this will be replaced.
    offset = 1.4;  // base offset, this will be replaced
    size   = 16;   // base offset, this will be replaced
}

Pizza::Pizza(char n[sizeOfName], int topping, int Price, double Offset, int Size) {
    SetName(n);
    numberOfToppings = topping;
    toppings = new Topping[numberOfToppings];
    currTopping = 0;
    price = Price; 
    offset = Offset;
    size   = Size;;
}
Pizza::~Pizza() {
    if (toppings != NULL){
        std::cout << "this is being called" << std::endl;
        delete [] toppings;
        toppings = NULL;
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
void Pizza::AddTopping(Topping topping, bool calcOffset){
    if (currTopping == numberOfToppings){
        resize();
    }
    if(calcOffset)
        topping.SetPrice(std::ceil(topping.GetPrice() * offset));
    toppings[currTopping] = topping;
    currTopping++;
    price += topping.GetPrice(); // costumer always looses part of a krona
}
std::ostream& operator<<(std::ostream &os,Pizza& pizza){
    os << pizza.GetName() << std::endl;
    os << pizza.GetPrice() << std::endl;
    os << pizza.GetNumberOfToppings()<< std::endl;
    for (int i=0; i< pizza.GetNumberOfToppings(); i++){
        os << "\t" << pizza.toppings[i];
    }
    return os;
}
void Pizza::WriteBin(std::ostream& BinaryOut){
    // Write information on this pizza
    Product::WriteBin(BinaryOut); 
    // number of toppings 
    BinaryOut.write((char*)(&currTopping), sizeof(int));
    for(int i = 0; i < currTopping; i++){
         // Write each of the topping to the stream
        toppings[i].WriteBin(BinaryOut);
    }
}
void Pizza::ReadBin(std::istream& BinaryIn){
    // Read the information on this pizza
    Product::ReadBin(BinaryIn); // this reads the name and price.
    int tempcurr = 0;
    BinaryIn.read((char*)(&tempcurr), sizeof(int));
    for(int i = 0; i < tempcurr; i++){
        Topping newtopping;
        newtopping.ReadBin(BinaryIn);
        AddTopping(newtopping, false);
    }
}
