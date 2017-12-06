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
    os << list;
}

void Sales::CreatePizza(Order order){
    int toppings;
    int size;
    char name[sizeOfName] = '\0'
    cout <<"what size? (16, 12 or 9)" <<endl;
    cin >> size;
    cout <<"How many toppings?" <<endl;
    cin >> toppings;
    Pizza pizza(name,size);
    //pizza = AddToppings(toppings,pizza);
    order.AddPizza(pizza);

}
void Sales::AddPizzaToOrder(int oid,int pid){
    FileHandler<Order> orders("activeOrders.obj");
    FileHandler<Pizza> pizzas("pizzamenu.obj");
    orders[oid].AddPizza(pizzas[pid]);
}
void Sales::AddOrder(Order &order){
    FileHandler<Order> list("orders.obj");
    list.AddProduct(order);
}
