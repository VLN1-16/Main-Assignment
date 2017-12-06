#include "sales.h"
Sales::Sales(){
    orderList = nullptr;
    inActiveOrderList = nullptr;
    pizzamenu = nullptr;
}
Sales::~Sales(){
    if(orderList != nullptr)
        delete orderList;
    if(inActiveOrderList != nullptr)
        delete inActiveOrderList;
    if(pizzamenu != nullptr)
        delete pizzamenu;
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
