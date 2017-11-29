#include "product.h"

Product::Product(){
    price = 0;
    name[0] = '\0';
    description[0] = '\0';
}
Product::Product(int p, char n[sizeOfName], char desc[sizeOfDesc]){
    price = p;
    SetName(n);
    SetDescription(desc);
}
Product::~Product(){

}
int Product::GetPrice() const{
    return price;
}
char* Product::GetName(){
    return name;
}
char* Product::GetDescription(){
    return description;
}

void Product::SetPrice(int p){
    price = p;
}
void Product::SetName(char n[sizeOfName]){
    for(int i = 0; i < sizeOfName;i++){
        name[i] = n[i];
    }
}
void Product::SetDescription(char desc[sizeOfDesc]){
    for(int i = 0; i < sizeOfDesc;i++){
        description[i] = desc[i];
    }
}

std::ostream& operator<<(std::ostream &os,Product& prod){
    os << prod.GetName() << std::endl;
    os << prod.GetPrice() << std::endl;
    os << prod.GetDescription() << std::endl;
    return os;
}
