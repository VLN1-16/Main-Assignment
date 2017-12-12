#include "inactiveorderrepo.h"

InActiveOrderRepo::InActiveOrderRepo(){
    orderList = new FileHandler<Order>(inactiveorderfile);
}

InActiveOrderRepo::~InActiveOrderRepo(){
    if(orderList != nullptr)
        delete orderList;
}
void InActiveOrderRepo::GetOrders(std::ostream &os){
    for(int i = 0; i < orderList->GetSize(); i++){
        os << "Order : " << i + 1 << std::endl;
        Order ord = orderList->at(i);
        os << ord;
    }
}
void InActiveOrderRepo::AddOrder(Order &order){
    orderList->AddProduct(order);
}
