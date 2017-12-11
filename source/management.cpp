#include "management.h"

Management::Management(){
    productlist = nullptr;
    pizzamenu = nullptr;
    toppinglist = nullptr;
    placelist = nullptr;
    pizzasizelist = nullptr;
}
Management::~Management(){
    if(productlist != nullptr)
        delete productlist;
    if(pizzamenu != nullptr)
        delete pizzamenu;
    if(toppinglist != nullptr)
        delete toppinglist;
    if(placelist != nullptr)
        delete placelist;
}
void Management::AddProduct(Product product){
    if(productlist == nullptr)
        productlist = new FileHandler<Product>(productfile);
    productlist->AddProduct(product);
}
void Management::GetProducts(std::ostream &os){
    if(productlist == nullptr)
        productlist = new FileHandler<Product>(productfile);
    for(int i = 0; i < productlist->GetSize(); i++){
        os << "Product : " << i + 1 << std::endl;
        os << productlist->at(i);
    }
}
void Management::RemoveProduct(int index){
    if(productlist == nullptr)
        productlist = new FileHandler<Product>(productfile);
    productlist->RemoveProduct(index);
}
void Management::AddPizzaSize(Pizzasize s){
    if(pizzasizelist == nullptr)
        pizzasizelist = new FileHandler<Pizzasize>(pizzasizefile);
    pizzasizelist->AddProduct(s);
}
void Management::GetPizzaSizes(std::ostream &os){
    if(pizzasizelist == nullptr)
        pizzasizelist = new FileHandler<Pizzasize>(pizzasizefile);
    for(int i = 0; i < pizzasizelist->GetSize(); i++){
        os << "BASE : " << i + 1 << std::endl;
        os << pizzasizelist->at(i);
    }
}
void Management::DeletePizzaSizeat(int index){
    if(pizzasizelist == nullptr)
        pizzasizelist = new FileHandler<Pizzasize>(pizzasizefile);
    pizzasizelist->RemoveProduct(index);
}
Pizzasize Management::GetPizzaSizeat(int index){
    if(pizzasizelist == nullptr)
        pizzasizelist = new FileHandler<Pizzasize>(pizzasizefile);
    return pizzasizelist->at(index);
}
void Management::AddTopping(Topping topping){
    if(toppinglist == nullptr)
        toppinglist = new FileHandler<Topping>(toppingfile);
    toppinglist->AddProduct(topping);
}
void Management::GetToppings(std::ostream &os){
    if(toppinglist == nullptr)
        toppinglist = new FileHandler<Topping>(toppingfile);
    for(int i = 0; i < toppinglist->GetSize(); i++){
        os << "Topping : " << i + 1 << std::endl;
        os << toppinglist->at(i);
    }
}
Topping Management::GetToppingat(int index){
    if(toppinglist == nullptr)
        toppinglist = new FileHandler<Topping>(toppingfile);
    return toppinglist->at(index);
}
void Management::RemoveTopping(int index){
    if(toppinglist == nullptr)
        toppinglist = new FileHandler<Topping>(toppingfile);
    toppinglist->RemoveProduct(index);
}
void Management::AddPlace(Place p){
    if(placelist == nullptr)
        placelist = new FileHandler<Place>(placefile);
    placelist->AddProduct(p);
}
void Management::GetPlaces(std::ostream& os){
    if(placelist == nullptr)
        placelist = new FileHandler<Place>(placefile);
    for(int i = 0; i < placelist->GetSize(); i++){
        os << "Place : " << i + 1 << std::endl;
        os << placelist->at(i);
    }
}
Place Management::GetPlace(int index){ 
    if(placelist == nullptr)
        placelist = new FileHandler<Place>(placefile);
    return placelist->at(index);
}
void Management::RemovePlace(int index){
    // this should set the active flag of a single place
    // this has to be implemented cleanly in filehandler 
}
void Management::AddPizza(Pizza& pizza){
    if(pizzamenu == nullptr)
        pizzamenu = new FileHandler<Pizza>(pizzafile);
    pizzamenu->AddProduct(pizza);
}
void Management::GetPizzas(std::ostream& os){
    if(pizzamenu == nullptr)
        pizzamenu = new FileHandler<Pizza>(pizzafile);
    for(int i = 0; i < pizzamenu->GetSize() ; i++){
        os << "Pizza : " << i + 1 << std::endl;
        os << pizzamenu->at(i);
    }
}
