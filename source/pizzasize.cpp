#include "pizzasize.h"

Pizzasize::Pizzasize(){
    size = 0;
    offset = 0;
    price = 0;
}
Pizzasize::Pizzasize(int s, double Offset, int Price){
    size = s;
    offset = Offset;
    price = Price;
}
int Pizzasize::GetPrice(){
    return price;
}
double Pizzasize::GetOffset(){
    return offset;
}
int Pizzasize::GetSize(){
    return size;
}
std::ostream& operator<<(std::ostream &os, Pizzasize& ps){
    os << ps.GetSize() << std::endl;
    os << ps.GetPrice() << std::endl;
    os << ps.GetOffset() << std::endl;
    return os;
}

void Pizzasize::WriteBin(std::ostream& binaryOut){
    // Write out the int and the name
    binaryOut.write((char*)(&size), sizeof(int));
    binaryOut.write((char*)(&price), sizeof(int));
    binaryOut.write((char*)(&offset), sizeof(double));
}
void Pizzasize::ReadBin (std::istream& binaryIn){
    binaryIn.read((char*)(&size), sizeof(int));
    binaryIn.read((char*)(&price), sizeof(int));
    binaryIn.read((char*)(&offset), sizeof(double));
}
