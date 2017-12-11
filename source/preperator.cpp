// for the one making the pizza it all depends on pizzas not orders.
// Active orders are stored as orders. Generate a list from that file of pizzas.
#include "preperator.h"

Preperator::Preperator(Place myplace){
    // Read in all active orders and place them in our
    // global pizza vector, all operations are then done on the vector
    // and modified into 
    activeorders = nullptr;
    this->myplace = myplace;
}
Preperator::~Preperator(){
    if(activeorders != nullptr)
        delete activeorders;
}
void Preperator::GetPizza(std::ostream& os, int index){
    if(activeorders == nullptr)
        activeorders = new FileHandler<Order>(orderfile); 
    if(pizzas.size() == 0)
        loadVec();
    if(index >= pizzas.size() || index < 0)
        throw IndexOutOfRangeException();
    os << pizzas[index] << std::endl;
}
void Preperator::loadVec(){
    int size;
    size = activeorders->GetSize();
    for(int i = 0; i < size; i++){
        // copy the Order
        Order order = activeorders->at(i);
        // go into each order and fetch all active pizzas with right place
        Place placeoforder;
        placeoforder = order.GetBranchLoc();
        // Compare places
        if(placeoforder == myplace){
            // loop through all the pizzas in this order and add it to the list
            int numberOfPizzas;
            numberOfPizzas = order.GetNumberOfPizzas();
            for(int j = 0; j < numberOfPizzas; j++){
                Pizza pizza;
                pizza = order.GetPizzaat(j);
                pizzas.push_back(pizza);
            }
        }
    }
}
// void Preperator::UpdateStatus(int index, int status){
//     if(activeorders == nullptr)
//         activeorders = new FileHandler<Order>(orderfile); 
//     // find the order the pizza is in 
//     // modify the pizza 
//     // write the entire active order list back into file
//     int internalindex = 0;
//     for(int i = 0; i < activeorders->GetSize(); i++){
//         if(activeorders->at(i).GetBranchLoc() == myplace){
//             // For all orders That are at my location
//             for(int j = 0; j < activeorders->at(i).GetNumberOfPizzas(); j++){
//                 if(index == internalindex){
//                     // at the right order and pizza
//                     // std::cout << "Found the pizza" << std::endl;
//                     // Pizza temp = activeorders->at(i).GetPizzaat(j);
//                     // std::cout << temp << std::endl;
//                     // Order tobechanged = activeorders->at(i);
//                     // std::cout << tobechanged << std::endl;
//                     // tobechanged.UpdatePizzaStatus(j, status); // j, how far i am into the order
//                     // activeorders->EditProduct(tobechanged, i); // Current orders index into active orders 
//                     return;
//                 }
//                 internalindex++; 
//             } 
//         }
//     }
//     // If both for loops where traversed and the index is not high enough,
//     // this index is invalid
//     throw IndexOutOfRangeException();
//     // because this function has to edit it is really gona be slow
// }
