#include "management.h"

Management::Management(){}
Management::~Management(){}
void Management::AddPizza(Pizza& pizza){
    FileHandler<Pizza> list("pizzamenu.obj");
    list.AddProduct(pizza);
}
void Management::AddProduct(Product product){
    FileHandler<Product> list("products.obj");
    list.AddProduct(product);
}
void Management::GetProducts(std::ostream &os){
    FileHandler<Product> list("products.obj");
    const std::vector<Product>* products = list.GetIteratableNonMutableList();
    for(unsigned int i = 0; i < products->size(); i++){
        os << "Product : " << i + 1 << std::endl;
        Product p = products->at(i);
        os << "\t" << p;
    }
}
void Management::RemoveProduct(int index){
    FileHandler<Product> list("products.obj");
    list.RemoveProduct(index);
}
void Management::AddPizzaSize(Pizzasize s){
    FileHandler<Pizzasize> list("pizzasizes.obj");
    list.AddProduct(s);
}
void Management::GetPizzaSizes(std::ostream &os){
    FileHandler<Pizzasize> list("pizzasizes.obj");
    const std::vector<Pizzasize>* pizzasizes = list.GetIteratableNonMutableList();
    for(unsigned int i = 0; i < pizzasizes->size(); i++){
        os << "BASE : " << i + 1 << std::endl;
        Pizzasize p = pizzasizes->at(i);
        os << "\t" << p;
    }
}
Pizzasize Management::GetPizzaSizeat(int index){
    FileHandler<Pizzasize> list("pizzasizes.obj");
    return list[index];
}
void Management::AddTopping(Topping topping){
    FileHandler<Topping> list("pizzatoppings.obj");
    list.AddProduct(topping);
}
void Management::GetToppings(std::ostream &os){
    FileHandler<Topping> list("pizzatoppings.obj");
    const std::vector<Topping>* toppings = list.GetIteratableNonMutableList();
    for(unsigned int i = 0; i < toppings->size(); i++){
        os << "Topping : " << i + 1 << std::endl;
        Topping t = toppings->at(i);
        os << "\t" << t;
    }
}
Topping Management::GetToppingat(int index){
    FileHandler<Topping> list("pizzatoppings.obj");
    return list[index];
}
void Management::RemoveTopping(int index){
    FileHandler<Topping> list("pizzatoppings.obj");
    list.RemoveProduct(index);
}
void GetProducts(std::ostream &os){
    FileHandler<Pizzasize> list("products.obj");
    os << list;
}
// void Management::GetPizzaSizes(std::ostream &os){
//     FileHandler<Pizzasize> list("pizzasizes.obj");
//     os << list;
// }
void Management::ChangePrice(int newPrice){

}

//void ListProducts(T product){}
void AddDeliveryPlace(Place place){

}
void Management::DeletePizzaSizeat(int index){
    FileHandler<Pizzasize> list("pizzasizes.obj");
    list.RemoveProduct(index);
}
void Management::AddPlace(Place p){
    FileHandler<Place> list("places.obj");
    list.AddProduct(p);
}
void Management::GetPlaces(std::ostream& os){
    FileHandler<Place> list("places.obj");
    const std::vector<Place>* places = list.GetIteratableNonMutableList();
    for(unsigned int i = 0; i < places->size(); i++){
        os << "Place : " << i + 1 << std::endl;
        Place p = places->at(i);
        os << "\t" << p;
    }
}
void Management::RemovePlace(int index){
    // this should set the active flag of a single place
    // this has to be implemented cleanly in filehandler 
}
void Management::GetPizzas(std::ostream& os){
    FileHandler<Pizza> list("pizzamenu.obj");
    const std::vector<Pizza>* pizzas = list.GetIteratableNonMutableList();
    for(unsigned int i = 0; i < pizzas->size(); i++){
        os << "Pizza : " << i + 1 << std::endl;
        Pizza p = pizzas->at(i);
        os << p;
    }
}
