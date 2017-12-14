#include "order.h"

Order::Order() {
    pickup = true;
    timestamp = time(0);
    ready = false;
    paid = false;
    price = 0;
    discount = 0;
    address[0] = '\0';
    comment[0] = '\0';

    products = nullptr;
    productcap = 2;
    numberOfProducts = 0;

    pizzas = nullptr;
    pizzacap = 2;
    numberOfPizzas = 0;
}

Order::Order(Costumer cost) : Order() {
    costumer = cost;
}
Order::Order(const Order& from) : Order(){
    pickup = from.pickup;
    timestamp = from.timestamp;
    ready = from.ready;
    paid = from.paid;
    discount = from.discount;
    costumer = from.costumer;
    BranchLoc = from.BranchLoc;
    for(int i = 0; i < from.numberOfPizzas; i++)
        AddPizza(from.pizzas[i]);
    for(int i = 0; i < from.numberOfProducts; i++)
        AddProduct(from.products[i]);
    for(int i = 0; i < sizeOfplace; i++)
        address[i] = from.address[i];
    for(int i = 0; i < sizeOfComment; i++)
        comment[i] = from.comment[i];
}
Order::~Order(){
    if(pizzas != nullptr){
        delete [] pizzas;
    }
    if(products != nullptr){
        delete [] products;
    }
}
void Order::AddProduct(Product& newproduct){
    if(products == nullptr)
        products = new Product[productcap];
    if(productcap == numberOfProducts)
        products = resize(products, productcap);

    products[numberOfProducts] = newproduct;
    numberOfProducts++;
    price += newproduct.GetPrice();
}
void Order::AddPizza(const Pizza& newpizza){
    if(pizzas == nullptr)
        pizzas = new Pizza[pizzacap];
    if(pizzacap == numberOfPizzas)
        pizzas = resize(pizzas, pizzacap);

    pizzas[numberOfPizzas] = newpizza;
    numberOfPizzas++;
    price += newpizza.GetPrice();
}

int Order::GetPrice(){
    return std::ceil(price *(1.0 - double(discount) / 100.0));
}
void Order::SetDiscount(int d){
    discount = d;
}
bool Order::IsReady(){
    return ready;
}
void Order::SetReady(){
    ready = true;
}
bool Order::IsPaid(){
    return paid;
}
void Order::SetPaid(){
    paid = true;
}

void Order::WriteBin(std::ostream& out){
    // Dynamic content
    // How many pizzas
    out.write((char*)(&numberOfPizzas), sizeof(int));
    // write each pizza
    for(int i = 0; i < numberOfPizzas; i++) pizzas[i].WriteBin(out);
    // How many products
    out.write((char*)(&numberOfProducts), sizeof(int));
    // write each product
    for(int i = 0; i < numberOfProducts; i++) products[i].WriteBin(out);

    // Static content
    out.write((char*)(&price), sizeof(int));
    out.write((char*)(&pickup), sizeof(bool));
    out.write((char*)(&timestamp),sizeof(long));
    out.write((char*)(&discount), sizeof(double));
    out.write((char*)(&ready),    sizeof(bool));
    out.write((char*)(&paid),    sizeof(bool));
    out.write((char*)(address),    sizeof(char)*sizeOfplace);
    out.write((char*)(comment),    sizeof(char)*sizeOfComment);
    costumer.WriteBin(out);
    BranchLoc.WriteBin(out);
}
void Order::ReadBin(std::istream& is){
    // Dynamic content
    // How many pizzas
    int number = 0;
    is.read((char*)(&number), sizeof(int));
    // read each pizza
    for(int i = 0; i < number; i++){
        Pizza newpizza;
        newpizza.ReadBin(is);
        AddPizza(newpizza);
    }
    // How many products
    is.read((char*)(&number), sizeof(int));
    // read each product
    for(int i = 0; i < number; i++){
        Product newproduct;
        newproduct.ReadBin(is);
        AddProduct(newproduct);
    }
    // Static content
    is.read((char*)(&price), sizeof(int));
    is.read((char*)(&pickup), sizeof(bool));
    is.read((char*)(&timestamp),sizeof(long));
    is.read((char*)(&discount), sizeof(double));
    is.read((char*)(&ready),    sizeof(bool));
    is.read((char*)(&paid),    sizeof(bool));
    is.read((char*)(address),    sizeof(char)*sizeOfplace);
    is.read((char*)(comment),    sizeof(char)*sizeOfComment);
    costumer.ReadBin(is);
    BranchLoc.ReadBin(is);
}
std::ostream& operator <<(std::ostream& out, Order& order){
    out << "Order : " << (!order.ready ? "IN PROGRESS" : "READY") << std::endl;
    out << "Delivery : " << (!order.pickup ? "HOME DELIVERY" : "PICKUP") << std::endl;
    out << "Delivery address: " << order.address << std::endl;
    if(!order.ready){
        out << "Status: ";
        long now = time(0);
        if((now - order.timestamp) > lateTime)
            out << "LATE" << std::endl;
        else if((now - order.timestamp) > ruinedTime)
            out << "RUINED" << std::endl;
        else
            out << "OK" << std::endl;
    }
    std::time_t create_time = order.timestamp;
    out << "Created : " << std::ctime(&create_time);
    out << "Costumer : " << order.costumer;
    out << "BranchLoc : " << order.BranchLoc << std::endl;
    if(order.numberOfProducts > 0)
        out << "Products(" << order.numberOfProducts << ") : " << std::endl;
    for(int i = 0; i < order.numberOfProducts; i++){
        out << order.products[i] << (i + 1 != order.numberOfProducts ? ",  " : "");
    }
    out << endl;
    if(order.numberOfPizzas > 0)
        out << "Pizzas(" << order.numberOfPizzas << ") : " << std::endl;
    for(int i = 0; i < order.numberOfPizzas; i++){
        out << order.pizzas[i];
    }
    out << std::endl;
    out << "Discount : " << order.discount << std::endl;
    out << "Total price : " << order.GetPrice() << std::endl;
    out << "Order Paid : " << (order.paid? "YES" : "NO") << std::endl;
    out << "Comment: " << order.comment << std::endl;
    return out;
}
bool Order::operator ==(Order& cmp){
    if(cmp.pickup != pickup) return false;
    if(cmp.timestamp != timestamp) return false;
    if(cmp.ready != ready) return false;
    if(cmp.paid != ready) return false;
    if(cmp.price != price) return false;
    if(cmp.discount != discount) return false;
    if(cmp.pickup != pickup) return false;
    if(cmp.paid != paid) return false;
    if(cmp.numberOfProducts != numberOfProducts) return false;
    for(int i = 0; i < numberOfProducts; i++)
        if(!(products[i] == cmp.products[i])) return false;
    if(cmp.numberOfPizzas != numberOfPizzas) return false;
    return true;
    for(int i = 0; i < numberOfPizzas; i++)
        if(!(pizzas[i] == cmp.pizzas[i])) return false;
    for(int i = 0; i < sizeOfplace; i++)
        if(!(address[i] == cmp.address[i])) return false;
    for(int i = 0; i < sizeOfComment; i++)
        if(!(comment[i] == cmp.comment[i])) return false;
    return true;
}
Order& Order::operator=(const Order& order){
    pickup = order.pickup;
    timestamp = order.timestamp;
    ready = order.ready;
    paid = order.paid;
    discount = order.discount;
    costumer = order.costumer;
    BranchLoc = order.BranchLoc;
    numberOfPizzas = 0;
    numberOfProducts = 0;
    for(int i = 0; i < order.numberOfPizzas; i++){
        AddPizza(order.pizzas[i]);
    }
    for(int i = 0; i < order.numberOfProducts; i++){
        AddProduct(order.products[i]);
    }
    for(int i = 0; i < sizeOfplace; i++)
        address[i] = order.address[i];
    for(int i = 0; i < sizeOfComment; i++)
        comment[i] = order.comment[i];
    return *this;
}
void Order::SetBranchLoc(Place& newplace){
    BranchLoc = newplace;
}
Place Order::GetBranchLoc() const{
    return BranchLoc;
}
Pizza Order::GetPizzaat(int index){
    if(index >= numberOfPizzas || index < 0)
        throw IndexOutOfRangeException();
    Pizza returnval = pizzas[index];
    return returnval;
}
int Order::GetNumberOfPizzas(){
    return numberOfPizzas;
}
void Order::UpdatePizzaStatus(int index, int status){
    if(index >= numberOfPizzas || index < 0)
        throw IndexOutOfRangeException();
    pizzas[index].SetStatus(status);
    bool temp = true;
    for (int i = 0; i < numberOfPizzas; i++){
        if(pizzas[i].GetStatus() != 2){
            temp = false;
            break;
        }
    }
    ready = temp;
}
Costumer Order::GetCostumer() const {
    return costumer;
}
void Order::HomeDelivery(std::string addr){
    pickup = false;
    for(int i = 0; i < sizeOfplace; i++){
        this->address[i] = addr[i];
        if(addr[i] == '\0') break;
    }
}
void Order::AddComment(std::string com){
    for(int i = 0; i < sizeOfComment; i++){
        this->comment[i] = com[i];
        if(com[i] == '\0') break;
    }
}
