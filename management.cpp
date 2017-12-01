Management(){}
~Management(){}
void AddTopping(Topping topping){
    FileHandler<Topping> list("pizzatoppings.obj");
    list.AddProduct(topping);
}
void AddPizza(Pizza pizza){
    FileHandler<Pizza> list("pizzamenu.obj");
    list.AddProduct(pizza);
}
void AddProduct(Product product){
    FileHandler<Pizza> list("pizzamenu.obj");
    list.AddProduct(pizza);
}
<template typename T>
void ChangePrice(T product, int newPrice){}
<template typename T>
void ListProducts(T product){}
void AddDeliveryPlace(char name[sizeOfplace],char address[sizeOfplace],char phone[7], bool = true){}
