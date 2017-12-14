#include "pizzasizerepo.h"
PizzaSizeRepo::PizzaSizeRepo(){
    pizzasizelist = new FileHandler<Pizzasize>(pizzasizefile); 
}
PizzaSizeRepo::~PizzaSizeRepo(){
    if(pizzasizelist != nullptr)
        delete pizzasizelist;
}
void PizzaSizeRepo::AddPizzaSize(Pizzasize s){
    pizzasizelist->AddProduct(s);
}
void PizzaSizeRepo::GetPizzaSizes(std::ostream &os){
    for(int i = 0; i < pizzasizelist->GetSize(); i++){
        os << "===== BASE : " << i + 1 << " =====" << std::endl;
        os << "BASE : " << i + 1 << std::endl << std::endl;
        Pizzasize pizzasize = pizzasizelist->at(i);
        os << pizzasize;
    }
}
void PizzaSizeRepo::DeletePizzaSizeat(int index){
    pizzasizelist->RemoveProduct(index);
}
Pizzasize PizzaSizeRepo::GetPizzaSizeat(int index){
    Pizzasize p = pizzasizelist->at(index);
    return p;
}
Pizzasize PizzaSizeRepo::GetPizzaSize(int index){
    return pizzasizelist->at(index);
}
int PizzaSizeRepo::GetNumberOfPizzaSizes() const{
    return pizzasizelist->GetSize();
}
