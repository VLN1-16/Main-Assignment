#include "orderrepo.h"
OrderRepo::OrderRepo(){
    orderList = new FileHandler<Order>(orderfile);
}
OrderRepo::~OrderRepo(){
    if(orderList != nullptr)
        delete orderList;
}
void OrderRepo::GetActiveOrders(std::ostream &os){
    for(int i = 0; i < orderList->GetSize(); i++){
        os << "Order : " << i + 1 << std::endl;
        Order ord = orderList->at(i);
        os << ord;
    }
}
void OrderRepo::GetActiveOrders(std::ostream &os, const Place& myplace){
    for(int i = 0; i < orderList->GetSize(); i++){
        Order ord = orderList->at(i);
        if(ord.GetBranchLoc() == myplace){
            os << "Order : " << i+1 << std::endl;
            os << ord;
        }
    }
}
void OrderRepo::GetReadyOrders(std::ostream &os,const Place& myplace){
    for(int i = 0; i < orderList->GetSize(); i++){
        Order ord = orderList->at(i);
        if(ord.GetBranchLoc() == myplace && ord.IsReady()){
            os << "Order : " << i+1 << std::endl;
            os << ord;
        }
    }
}
void OrderRepo::ReadOrderAt(std::ostream &os, int index){
    Order ord = orderList->at(index);
    os << ord;
}
void OrderRepo::AddOrder(Order &order){
    // Here some order validation has to occur.
    orderList->AddProduct(order);
}
Order OrderRepo::GetOrderAt(int index){
    return orderList->at(index);
}
void OrderRepo::GetPizzaByPlace(std::ostream&os, const int index, const Place& myplace){
    // If the pizza list is empty, fill it (don't do this at the start if somebody else is calling the class )
    if(pizzas.size() == 0)
        FillPizzaVector(myplace);
    if(index >= pizzas.size() || index < 0) // if the pizza vector is empty, throw an exception
        throw IndexOutOfRangeException();
    os << pizzas[index] << std::endl;
}

void OrderRepo::UpdatePizzaStatus(int index, const int status, const Place& myplace){
    if(index >= pizzas.size() || index < 0) throw IndexOutOfRangeException(); // Idea is that for this to be running the vector has to be loaded
    int currindex = 0;
    for(int i = 0; i < orderList->GetSize(); i++){
        // copy the Order
        Order order = orderList->at(i);
        // Compare places
        if(order.GetBranchLoc() == myplace){
            // loop through all the pizzas in this order and add it to the list
            for(int j = 0; j < order.GetNumberOfPizzas(); j++){
                if(currindex == index){
                    // at the right pizza
                    order.UpdatePizzaStatus(j, status); // j is the index of the pizza inside this order, modify that's pizza status
                    if(order.AllPizzasReady()){
                        order.SetReady();
                    }
                    orderList->EditProduct(order, i); // i is the number of product inside of orderlist, replace current with that
                    std::cout << "Found the pizza at index  : " << currindex << std::endl;
                    pizzas.clear();
                }
                currindex++;
            }
        }
    }
}
void OrderRepo::RemoveOrder(int index){
    if(index < orderList->GetSize() && index >= 0){
        Order order;
        order = orderList->at(index);
        orderList->RemoveProduct(index);
        }
    else {
        // index IndexOutOfRangeException();
    }
}
void OrderRepo::MarkPaid(int index){
    if(index < orderList->GetSize() && index >= 0){
        Order order = orderList->at(index);
        order.SetPaid();
        orderList->EditProduct(order,index);
    }
}
void OrderRepo::FillPizzaVector(const Place& myplace){
    for(int i = 0; i < orderList->GetSize(); i++){
        // copy the Order
        Order order = orderList->at(i);
        // Compare places
        if(order.GetBranchLoc() == myplace){
            // loop through all the pizzas in this order and add it to the list
            for(int j = 0; j < order.GetNumberOfPizzas(); j++){
                pizzas.push_back(order.GetPizzaat(j));
            }
        }
    }
}
