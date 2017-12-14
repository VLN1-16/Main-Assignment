#include "orderrepo.h"
OrderRepo::OrderRepo(){
    orderList = new FileHandler<Order>(orderfile);
}
OrderRepo::~OrderRepo(){
    if(orderList != nullptr)
        delete orderList;
}
void OrderRepo::printasingleorder(ostream& os, Order ord, const int numberof){
        os << std::endl;
        os << "============================================================== Order : " << numberof << " ==============================================================" << std::endl;
        os << ord;
}
void OrderRepo::GetActiveOrders(std::ostream &os){
    for(int i = 0; i < orderList->GetSize(); i++)
        printasingleorder(os, orderList->at(i), i + 1);
}
void OrderRepo::GetActiveOrders(std::ostream &os, const Place& myplace){
    for(int i = 0; i < orderList->GetSize(); i++)
        if(orderList->at(i).GetBranchLoc() == myplace)
            printasingleorder(os, orderList->at(i), i + 1);
}
void OrderRepo::GetOrdersByCostumer(std::ostream &os, const Place& myplace, char phone[8]){
    int count = 0;
    for(int i = 0; i < orderList->GetSize(); i++){
        Order ord = orderList->at(i);
        if(ord.GetBranchLoc() == myplace && ord.GetCostumer().CompareNumber(phone)){
            printasingleorder(os, ord, i + 1);
            count++;
        }
    }
    if (count == 0) throw IndexOutOfRangeException();
}
void OrderRepo::GetReadyOrders(std::ostream &os,const Place& myplace){
    for(int i = 0; i < orderList->GetSize(); i++){
        Order ord = orderList->at(i);
        if(ord.GetBranchLoc() == myplace && ord.IsReady()){
            os << "============================================================== Order : " << i + 1 << " ==============================================================" << std::endl;
            os << ord;
        }
    }
}
void OrderRepo::ReadOrderAt(std::ostream &os, int index,const Place& myplace){
    if(index >= orderList->GetSize() || index < 0) // if the pizza vector is empty, throw an exception
        throw IndexOutOfRangeException();
    Order ord = orderList->at(index);
    if(ord.GetBranchLoc() == myplace)
        os << ord;
    else
        throw IndexOutOfRangeException();
}
void OrderRepo::AddOrder(Order &order){
    // Here some order validation has to occur.
    orderList->AddProduct(order);
}
Order OrderRepo::GetOrderAt(int index){
    return orderList->at(index);
}
void OrderRepo::GetPizzaByPlace(std::ostream&os, const unsigned int index, const Place& myplace){
    // If the pizza list is empty, fill it (don't do this at the start if somebody else is calling the class )
    if(pizzas.size() == 0)
        FillPizzaVector(myplace);
    if(index >= pizzas.size()) // if the pizza vector is empty, throw an exception
        throw IndexOutOfRangeException();
    os << pizzas[index].first;
    os << pizzas[index].second << std::endl;
}

void OrderRepo::UpdatePizzaStatus(const unsigned int index, const int status, const Place& myplace){
    if(index >= pizzas.size()) throw IndexOutOfRangeException(); // Idea is that for this to be running the vector has to be loaded
    unsigned int currindex = 0;
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
                    orderList->EditProduct(order, i); // i is the number of product inside of orderlist, replace current with that
                    std::cout << "Found the pizza at index  : " << currindex << std::endl;
                    pizzas.clear();
                }
                currindex++;
            }
        }
    }
}
void OrderRepo::RemoveOrder(int index, const Place& myplace){
    if(index < orderList->GetSize() && index >= 0){
        Order order;
        order = orderList->at(index);
        if (!(order.GetBranchLoc() == myplace)) throw InvalidPaymentLocation();
        orderList->RemoveProduct(index);
        }
    else {
        throw IndexOutOfRangeException();
    }
}
void OrderRepo::MarkPaid(int index, const Place& myplace){
    if(index < orderList->GetSize() && index >= 0){
        Order order = orderList->at(index);
        if (!(order.GetBranchLoc() == myplace)) throw InvalidPaymentLocation();
        order.SetPaid();
        orderList->EditProduct(order,index);
    }
    else{
        throw IndexOutOfRangeException();
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
                pizzas.push_back(std::make_pair(order.GetPizzaat(j),order.GetComment()));
            }
        }
    }
}
const int OrderRepo::GetNumberOfPizzas(){
    // For this to run loadvec has to have been run
    return pizzas.size();
}
const int OrderRepo::GetNumberOfOrders(){
    return orderList->GetSize();
}
const int OrderRepo::GetNumberOfOrders(const Place& myplace){
    int count = 0;
    for(int i = 0; i < orderList->GetSize(); i++){
        Order ord = orderList->at(i);
        if(ord.GetBranchLoc() == myplace)
            count++;
    }
    return count;
}
const int OrderRepo::GetNumberOfReadyOrders(const Place& myplace){
    int count = 0;
    for(int i = 0; i < orderList->GetSize(); i++){
        Order ord = orderList->at(i);
        if(ord.GetBranchLoc() == myplace && ord.IsReady())
            count++;
    }
    return count;
}
void OrderRepo::EditOrder(int index, const Order& order){
    orderList->EditProduct(order,index);
}
