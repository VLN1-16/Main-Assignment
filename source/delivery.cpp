Delivery::Delivery(Place place){
    this->myplace = place;
    orders = nullptr;
    inactiveorders = nullptr;
}
~Delivery::Delivery();
void Delivery::GetOrders(std::ostream& os){
    int j = 1;
    if(activeorders == nullptr)
        orders = new FileHandler<Order>(activeorderfile);
    for(int i = 0; i < activeorders->GetSize(); i++){
        if(activeorders->at(i).GetBranchLoc() == myplace){
            os << "Order : " << j << std::endl;
            os << activeorders->at(i);
            j++;
        }

    }
}
void Delivery::loadVec(){
    for(int i = 0; i < orders->GetSize(); i++){
        // go into each order and fetch all active pizzas with right place
        if(orders->at(i).GetBranchLoc() == myplace){
            // all pizzas inside this order should go into pizzas
            
        }
    }
}
void Delivery::MarkDelivered(int index);
