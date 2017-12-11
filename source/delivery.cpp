#include "delivery.h"

Delivery::Delivery(Place place){
    this->myplace = place;
    activeorders = nullptr;
    inactiveorders = nullptr;
}
Delivery::~Delivery(){
    if(activeorders != nullptr)
        delete activeorders;
    if(inactiveorders != nullptr)
        delete activeorders;
}
void Delivery::GetOrders(std::ostream& os){
    if(activeorders == nullptr)
        activeorders = new FileHandler<Order>(activeorderfile);
    for(int i = 0; i < activeorders->GetSize(); i++){
        Order ord = activeorders->at(i);
        if(ord.GetBranchLoc() == myplace){
            os << "Order : " << i+1 << std::endl;
            os << ord;
        }
    }
}
void Delivery::GetReadyOrders(std::ostream& os){
    if(activeorders == nullptr)
        activeorders = new FileHandler<Order>(activeorderfile);
    for(int i = 0; i < activeorders->GetSize(); i++){
        Order ord = activeorders->at(i);
        if(ord.GetBranchLoc() == myplace && ord.IsReady()){
            os << "Order : " << i+1 << std::endl;
            os << ord;
        }
    }
}
void Delivery::GetThisOrder(std::ostream& os,int orderid){
    if(activeorders == nullptr)
        activeorders = new FileHandler<Order>(activeorderfile);
    Order ord = activeorders->at(orderid);
    os << ord;
}
void Delivery::MarkDelivered(int index){
    if(index < activeorders->GetSize() && index >= 0){
        Order order;
        order = activeorders->at(index);
        if(order.IsPaid()){
            if(inactiveorders == nullptr){
                inactiveorders = new FileHandler<Order>(inactiveorderfile);
            }
            inactiveorders->AddProduct(order);
            activeorders->RemoveProduct(index);
        }
        else {
            // Exception stuff
        }

    }
}
void Delivery::MarkPaid(int index){
    if(index < activeorders->GetSize() && index >= 0){
        Order order = activeorders->at(index);
        order.SetPaid();
        activeorders->EditProduct(order,index);
    }
}
