#include "management.h"

Management::Management(){}
Management::~Management(){}
void Management::AddTopping(Topping topping){
    FileHandler<Topping> list("pizzatoppings.obj");
    list.AddProduct(topping);
}
void Management::AddPizza(Pizza pizza){
    FileHandler<Pizza> list("pizzamenu.obj");
    list.AddProduct(pizza);
}
void Management::AddProduct(Product product){
    FileHandler<Product> list("products.obj");
    list.AddProduct(product);
}
void Management::AddPizzaSize(Pizzasize s){
    Pizzasize size(s);
    FileHandler<Pizzasize> list("pizzasizes.obj");
    list.AddProduct(size);
}
void GetPizzas(std::ostream &os){
    FileHandler<Pizzasize> list("pizzamenu.obj");
    os << list;
}
void GetToppings(std::ostream &os){
    FileHandler<Pizzasize> list("pizzatoppings.obj");
    os << list;
}
void GetProducts(std::ostream &os){
    FileHandler<Pizzasize> list("products.obj");
    os << list;
}
void Management::GetPizzaSizes(std::ostream &os){
    FileHandler<Pizzasize> list("pizzasizes.obj");
    os << list;
}
void Management::ChangePrice(int newPrice){

}

//void ListProducts(T product){}
void AddDeliveryPlace(Place place){

}
