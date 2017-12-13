#include "deliveryUI.h"

DeliveryUI::DeliveryUI(Place Myplace){
    myplace = Myplace;
    orders = new OrderRepo();
    inorders = new InActiveOrderRepo();
}
DeliveryUI::~DeliveryUI(){
    if(orders != nullptr){
        delete orders;
    }
    if(inorders != nullptr){
        delete inorders;
    }
}
void DeliveryUI::DeliveryMenu(){

    while(true){
        cout << "a: Get list of all orders for this place" << endl;
        cout << "r: Get list of ready orders for this place" << endl;
        cout << "i: Get a specific order by index" << endl;
        cout << "c: Geta orders for a specific customer" << endl;
        cout << "b: Back" << endl;
        cout << "q: quit" << endl;
        char userin;
        cin >> userin;
        switch(tolower(userin)){
            case 'a':
                cout << "All active orders at this place:" << endl;
                orders->GetActiveOrders(cout,myplace);
                cout << endl;
                break;
            case 'r':
                cout << "All ready orders" << endl;
                orders->GetReadyOrders(cout,myplace);
                cout << endl;
                break;
            case 'i':
                int id;
                cout << "Select An order: " << endl;
                //orders->GetActiveOrders(cout,myplace);
                cin >> id;
                orders->ReadOrderAt(cout,id-1);
                EditDelivery(id-1);
                break;
            case 'c':
                char p[8];
                cout << "What is the customers phonenumber " << endl;
                cin >> p;
                orders->GetOrdersByCostumer(cout,myplace,p);
                break;
            case 'b':
                return;
            case 'q':
                exit(0);
            default:
                cout << "Invalid input! " << endl;
        }
    }
}
void DeliveryUI::EditDelivery(int index){
    cout << "a: Mark order as paid" << endl;
    cout << "d: Mark order as delivered" << endl;
    cout << "r: Mark order as paid and delivered" << endl;
    cout << "b: Back" << endl;
    cout << "q: quit" << endl;
    char userin;
    cin >> userin;
    switch(tolower(userin)){
        case 'a':{
            orders->MarkPaid(index,myplace);
            break;
        }
        case 'd':{
            MakeDelivered(index);
            break;
        }
        case 'r':{
            orders->MarkPaid(index,myplace);
            MakeDelivered(index);
            break;
        }
        case 'b':{
            return;
        }
        case 'q':{
            exit(0);
        }
    }
}
void DeliveryUI::MakeDelivered(int index){
    Order order = orders->GetOrderAt(index);
    if(order.IsPaid()){
        inorders->AddOrder(order);
        orders->RemoveOrder(index,myplace);
    }
    else{
        // ORDER NOT PAID EXCEPTION
    }

}
