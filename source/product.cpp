#include "product.h"

Product::Product(){
    price = 0;
    name[0] = '\0';
}
Product::Product(int p, char n[sizeOfName]){
    price = p;
    SetName(n);
}
Product::Product(char n[sizeOfName], int p) : Product(p, n) {
}
Product::~Product(){

}
int Product::GetPrice() const{
    return price;
}
char* Product::GetName(){
    return name;
}

void Product::SetPrice(const int& p){
    price = p;
}
void Product::SetName(const char n[sizeOfName]){
    for(int i = 0; i < sizeOfName;i++){
        name[i] = n[i];
    }
}
std::ostream& operator<<(std::ostream &os, Product& prod){
    os << prod.GetName() << " ";
    os << prod.GetPrice() << std::endl;
    return os;
}
std::istream& operator>>(std::istream &is, Product &prod){
    is >> prod.name >> prod.price;
    return is;
}
void Product::WriteBin(std::ostream& binaryOut){
    // Write out the int and the name
    binaryOut.write((char*)(&price), sizeof(int));
    binaryOut.write((char*)(name), sizeof(char) * sizeOfName);
}
void Product::ReadBin (std::istream& binaryIn){
    binaryIn.read((char*)(&price), sizeof(int));
    binaryIn.read((char*)(name), sizeof(char) * sizeOfName);
}
bool Product::operator ==(Product& prod1){
    bool NameTheSame = true;
    for(int i = 0; i < sizeOfName; i++){
        if(prod1.name[i] == name[i]){
            if(name[i] == '\0') break; 
        }
        else{
            return false;
        }
    }
    return prod1.GetPrice() == price && NameTheSame;
}