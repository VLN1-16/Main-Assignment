#include "order.h"

Order::Order(){
    pickup = true;
    paid = false;
    timestamp = time(0);
    ready = false;

    price = 0;
    discount = 0;

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
        return price;
}
void SetPaid(){
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
    costumer.WriteBin(out);
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
        // products[i].WriteBin(out);
    }
    // Static content
    is.read((char*)(&price), sizeof(int));
    is.read((char*)(&pickup), sizeof(bool));
    is.read((char*)(&timestamp),sizeof(long));
    is.read((char*)(&discount), sizeof(double));
    is.read((char*)(&ready),    sizeof(bool));
    is.read((char*)(&paid),    sizeof(bool));
    costumer.ReadBin(is);
}
std::ostream& operator <<(std::ostream& out, Order& order){
    out << "Order : " << (!order.ready ? "IN PROGRESS" : "DELIVERED") << std::endl;
    out << "Created stamp : " << order.timestamp << std::endl;
    out << "Costumer : " << order.costumer;
    if(order.numberOfProducts > 0)
        out << "Products(" << order.numberOfProducts << ") : " << std::endl;
    for(int i = 0; i < order.numberOfProducts; i++){
        out << "\t" << order.products[i];
    }
    if(order.numberOfPizzas > 0)
        out << "Pizzas(" << order.numberOfPizzas << ") : " << std::endl;
    for(int i = 0; i < order.numberOfPizzas; i++){
        out << order.pizzas[i];
    }
    out << "Discount : " << order.discount << std::endl;
    out << "Total price : " << order.GetPrice() << std::endl;
    out << "Paid : " << (!order.paid ? "YES" : "NO") << std::endl;

    return out;
}
bool Order::operator ==(Order& cmp){
    if(cmp.pickup != pickup) return false;
    if(cmp.timestamp != timestamp) return false;
    if(cmp.ready != ready) return false;
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
    return true;
}
Order& Order::operator=(const Order& order){
    std::cout << "Copy constructor got called" << std::endl;
    pickup = order.pickup;
    timestamp = order.timestamp;
    ready = order.ready;
    paid = order.paid;
    discount = order.discount;
    costumer = order.costumer;
    for(int i = 0; i < order.numberOfPizzas; i++){
        AddPizza(order.pizzas[i]);
    }
    for(int i = 0; i < order.numberOfProducts; i++){
        AddProduct(order.products[i]);
    }
    return *this;
}
void Order::SetBranchLoc(Place& newplace){
    BranchLoc = newplace;
}
Place Order::GetBranchLoc(){
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
