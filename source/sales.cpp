#include "sales.h"


void Sales::GetActiveOrders(std::ostream &os){
    FileHandler<Order> list("orders.obj");
    const std::vector<Order>* orders = list.GetIteratableNonMutableList();
    for(unsigned int i = 0; i < orders->size(); i++){
        os << "Order : " << i + 1 << std::endl;
        Order o = orders->at(i);
        os << o;
    }
    delete orders;
}
void Sales::GetInActiveOrders(std::ostream &os){
    FileHandler<Order> list("inActiveOrders.obj");
    const std::vector<Order>* orders = list.GetIteratableNonMutableList();
    for(unsigned int i = 0; i < orders->size(); i++){
        os << "Order : " << i + 1 << std::endl;
        Order o = orders->at(i);
        os << o;
    }
    delete orders;
}
void Sales::GetPizzas(std::ostream &os){
    FileHandler<Pizza> list("pizzamenu.obj");
    const std::vector<Pizza>* pizzas = list.GetIteratableNonMutableList();
    for(unsigned int i = 0; i < pizzas->size(); i++){
        os << "Pizza : " << i + 1 << std::endl;
        Pizza p = pizzas->at(i);
        os << p;
    }
    delete pizzas;
}
Pizza Sales::GetPizza(int id){
    FileHandler<Pizza> list("pizzamenu.obj");
    const std::vector<Pizza>* pizzas = list.GetIteratableNonMutableList();
    Pizza p = pizzas->at(id);
    delete pizzas;
    
    return p;
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
<<<<<<< HEAD
    orders[oid].AddPizza(pizzas[pid]);
=======
    const std::vector<Topping>* pizza = pizzas.GetIteratableNonMutableList();
    orders[oid].AddPizza(pizza[pid]);
    */
}
Order Sales::GetThisOrder(int orderid){
    FileHandler<Order> list("activeOrders.obj");
    const std::vector<Order>* orders = list.GetIteratableNonMutableList();
    Order o = orders->at(orderid);
    delete orders;

    return o;
>>>>>>> removed a cpp file and changed the resize inside filehandler
}
void Sales::AddOrder(Order &order){
    FileHandler<Order> list("orders.obj");
    list.AddProduct(order);
}
