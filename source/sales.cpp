#include "sales.h"
Sales::Sales(){
    orderList = nullptr;
    inActiveOrderList = nullptr;
    pizzamenu = nullptr;
    productList = nullptr;
    toppingList = nullptr;
    pizzasizes  = nullptr;
}
Sales::~Sales(){
    if(orderList != nullptr)
        delete orderList;
    if(inActiveOrderList != nullptr)
        delete inActiveOrderList;
    if(pizzamenu != nullptr)
        delete pizzamenu;
    if(toppingList != nullptr)
        delete toppingList;
    if(pizzasizes != nullptr)
        delete pizzasizes;
}
void Sales::GetActiveOrders(std::ostream &os){
    if(orderList == nullptr)
        orderList = new FileHandler<Order>(orderfile);
    for(int i = 0; i < orderList->GetSize(); i++){
        os << "Order : " << i + 1 << std::endl;
        os << orderList->at(i);
    }
}
void Sales::GetInActiveOrders(std::ostream &os){
    if(inActiveOrderList == nullptr)
        inActiveOrderList = new FileHandler<Order>(inActiveOrderListfile);
    for(int i = 0; i < inActiveOrderList->GetSize(); i++){
        os << "Order : " << i + 1 << std::endl;
        os << inActiveOrderList->at(i);
    }
}
void Sales::GetPizzas(std::ostream &os){
    if(pizzamenu == nullptr)
        pizzamenu = new FileHandler<Pizza>(pizzafile);
    for(int i = 0; i < pizzamenu->GetSize(); i++){
        os << "Pizza : " << i + 1 << std::endl;
        os << pizzamenu->at(i);
    }
}
Pizza Sales::GetPizza(int index){
    if(pizzamenu == nullptr)
        pizzamenu = new FileHandler<Pizza>(pizzafile);
    return pizzamenu->at(index);
}
void Sales::AddOrder(Order &order){
    if(orderList == nullptr)
        orderList = new FileHandler<Order>(orderfile);
    orderList->AddProduct(order);
}
Order Sales::GetThisOrder(int orderid){
    if(orderList == nullptr)
        orderList = new FileHandler<Order>(orderfile);
    return orderList->at(orderid);
}
void Sales::GetProducts(std::ostream& os){
    if(productList == nullptr)
        productList = new FileHandler<Product>(productfile);
    for(int i = 0; i < productList->GetSize(); i++){
        os << "Product : " << i + 1 << std::endl;
        os << productList->at(i);
    }
    
}
Product Sales::GetProduct(int index){
    if(productList == nullptr)
        productList = new FileHandler<Product>(productfile);
    return productList->at(index); 
}
void Sales::GetToppings(std::ostream& os){
    if(toppingList == nullptr)
        toppingList = new FileHandler<Topping>(toppingfile);
    for(int i = 0; i < toppingList->GetSize(); i++){
        os << "Topping : " << i + 1 << std::endl;
        os << toppingList->at(i);
    }
}
Topping Sales::GetTopping(int index){
    if(toppingList == nullptr)
        toppingList = new FileHandler<Topping>(toppingfile);
    return toppingList->at(index);
}
Pizzasize Sales::GetPizzaSize(int index){
    if(pizzasizes == nullptr)
        pizzasizes = new FileHandler<Pizzasize>(pizzasizefile);
    return pizzasizes->at(index);
}
void Sales::GetPizzaSizes(std::ostream& os){
    if(pizzasizes == nullptr)
        pizzasizes = new FileHandler<Pizzasize>(pizzasizefile);
    for(int i = 0; i < pizzasizes->GetSize(); i++){
        os << "PizzaSize : " << i + 1 << std::endl;
        os << pizzasizes->at(i);
    }
}
