// for the one making the pizza it all depends on pizzas not orders.
// Active orders are stored as orders. Generate a list from that file of pizzas.
#include "preperator.h"

Preperator::Preperator(Place myplace){ // ctor
    // Read in all active orders and place them in our
    // global pizza vector, all operations are then done on the vector
    // and modified into
    activeorders = nullptr;
    this->myplace = myplace;
}
Preperator::~Preperator(){ // dtor
    if(activeorders == nullptr)
        delete activeorders;
}
void Preperator::GetPizza(std::ostream& os, int index){
    if(activeorders == nullptr)
        activeorders = new FileHandler<Order>(orderfile) ; // what was the datafile
    if(pizzas.size() == 0)
        loadVec();
    // os << activeorders->at(index) << std::endl;
    if(index >= pizzas.size() || index < 0)
        throw IndexOutOfRangeException();
    os << pizzas[index] << std::endl;
}
void Preperator::loadVec(){
    for(int i = 0; i < activeorders->GetSize(); i++){
        // go into each order and fetch all active pizzas with right place
        Place placeoforder = activeorders->at(i).GetBranchLoc();
        // Compare places
        if(activeorders->at(i).GetBranchLoc() == myplace){
            // loop through 
            for(int j = 0; j < activeorders->at(i).GetNumberOfPizzas(); j++){
                pizzas.push_back(activeorders->at(i).GetPizzaat(j));
            }
        }
    }
}
void Preperator::UpdateStatus(int index, int status){
    // find the order the pizza is in 
    // modify the pizza 
    // write the entire active order list back into file
    for(int i = 0; i < activeorders.GetSize(); i++){
         
    }
    // because this function has to edit it is really gona be slow
}
