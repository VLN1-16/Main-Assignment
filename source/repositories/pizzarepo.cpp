#include "pizzarepo.h"

PizzaRepo::PizzaRepo(){
    pizzamenu = new FileHandler<Pizza>(pizzafile);
}
PizzaRepo::~PizzaRepo(){
    delete pizzamenu;
}
void PizzaRepo::AddPizza(Pizza& pizza){
    // Here some validation is needed to check the pizza
    pizzamenu->AddProduct(pizza);
}
void PizzaRepo::GetPizzas(std::ostream &os){
    for(int i = 0; i < pizzamenu->GetSize(); i++){
        os << "Pizza : " << i + 1 << std::endl;
        Pizza pizza;
        pizza = pizzamenu->at(i);
        os << pizza;
    }
}
Pizza PizzaRepo::GetPizza(int index){
    return pizzamenu->at(index);
}
int PizzaRepo::GetNumberOfPizzas() const{
    return pizzamenu->GetSize();
}
void PizzaRepo::RemovePizza(int index){
    pizzamenu->RemoveProduct(index);
}
