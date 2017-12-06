#include "sales.h"


void Sales::GetActiveOrders(std::ostream &os){
    FileHandler<Order> list("orders.obj");
    const std::vector<Order>* orders = list.GetIteratableNonMutableList();
    for(unsigned int i = 0; i < orders->size(); i++){
        os << "Order : " << i + 1 << std::endl;
        Order o = orders->at(i);
        os << o;
    }
}
void Sales::GetInActiveOrders(std::ostream &os){
    FileHandler<Order> list("inActiveOrders.obj");
    const std::vector<Order>* orders = list.GetIteratableNonMutableList();
    for(unsigned int i = 0; i < orders->size(); i++){
        os << "Order : " << i + 1 << std::endl;
        Order o = orders->at(i);
        os << o;
    }
}
void Sales::GetPizzas(std::ostream &os){
    FileHandler<Pizza> list("pizzamenu.obj");
    const std::vector<Pizza>* pizzas = list.GetIteratableNonMutableList();
    for(unsigned int i = 0; i < pizzas->size(); i++){
        os << "Pizza : " << i + 1 << std::endl;
        Pizza p = pizzas->at(i);
        os << p;
    }
}
Pizza Sales::GetPizza(int id){
    FileHandler<Pizza> list("pizzamenu.obj");
    const std::vector<Pizza>* pizzas = list.GetIteratableNonMutableList();
    Pizza p = pizzas->at(id);
    return p;
}
void Sales::CreatePizza(Order order){


}
void Sales::AddPizzaToOrder(int oid,int pid){
    /* FileHandler<Order> orders("activeOrders.obj");
    FileHandler<Pizza> pizzas("pizzamenu.obj");
    const std::vector<Topping>* pizza = pizzas.GetIteratableNonMutableList();
    orders[oid].AddPizza(pizza[pid]);
    */
}
Order Sales::GetThisOrder(int orderid){
    FileHandler<Order> list("activeOrders.obj");
    const std::vector<Order>* orders = list.GetIteratableNonMutableList();
    Order o = orders->at(orderid);
    return o;
}
void Sales::AddOrder(Order &order){
    FileHandler<Order> list("orders.obj");
    list.AddProduct(order);
}
