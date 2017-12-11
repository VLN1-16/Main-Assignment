#include "orderrepo.h"
OrderRepo::OrderRepo(){

}
~OrderRepo::OrderRepo(){

}
void OrderRepo::GetActiveOrders(std::ostream &os){
    for(int i = 0; i < orderList->GetSize(); i++){
        os << "Order : " << i + 1 << std::endl;
        Order ord = orderList->at(i);
        os << ord;
    }
}
void OrderRepo::AddOrder(Order &order){
    // Here some order validation has to occur.
    orderList->AddProduct(order);
}
Order OrderRepo::GetOrderAt(int index){
    return orderList->at(index);
}
