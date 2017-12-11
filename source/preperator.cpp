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
    os << pizzas[index] << std::endl;
}
void Preperator::loadVec(){
    for(int i = 0; i < activeorders->GetSize(); i++){
        // go into each order and fetch all active pizzas with right place
        if(activeorders->at(i).GetBranchLoc() == myplace){
            // all pizzas inside this order should go into pizzas
            for(int j = 0; i < activeorders->at(i).GetNumberOfPizzas(); j++){
                Pizza currPizza = activeorders->at(i).GetPizzaat(j);
                std::cout << currPizza;
                // pizzas.push_back(activeorders->at(i).GetPizzaat(j));
            }
        }
    }
}
