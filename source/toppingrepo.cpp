#include "toppingrepo.h"
ToppingRepo::ToppingRepo(){
    toppinglist = new FileHandler<Topping>(toppingfile);
}
ToppingRepo::~ToppingRepo(){
    if(toppinglist != nullptr){
        delete toppinglist;
    }
}
void ToppingRepo::AddTopping(Topping topping){
    toppinglist->AddProduct(topping);
}
void ToppingRepo::GetToppings(std::ostream &os){
    for(int i = 0; i < toppinglist->GetSize(); i++){
        os << "===== Topping : " << i + 1 << " =====" << std::endl;
        Topping top = toppinglist->at(i);
        os << top << std::endl;
    }
}
void ToppingRepo::RemoveTopping(int index){
    toppinglist->RemoveProduct(index);
}
Topping ToppingRepo::GetToppingat(int index){
    return toppinglist->at(index); // I think this does not work
}
Topping ToppingRepo::GetTopping(int index){
    return GetToppingat(index);
}
