#include "product.h"

Product::Product(){
    price = 0;
    name[0] = '\0';
}
Product::Product(int p, char n[sizeOfName]){
    price = p;
    SetName(n);
}
Product::~Product(){

}
int Product::GetPrice() const{
    return price;
}
char* Product::GetName(){
    return name;
}

void Product::SetPrice(int p){
    price = p;
}
void Product::SetName(char n[sizeOfName]){
    for(int i = 0; i < sizeOfName;i++){
        name[i] = n[i];
    }
}

std::ostream& operator<<(std::ostream &os,Product& prod){
    os << prod.GetName() << " ";
    os << prod.GetPrice() << std::endl;
    return os;
}
