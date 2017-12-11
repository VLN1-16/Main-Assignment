#include "deliveryUI.h"

DeliveryUI::DeliveryUI(Place Myplace){
    this->myplace = Myplace;
    dev = nullptr;
}
DeliveryUI::~DeliveryUI(){
    if(dev != nullptr){
        delete dev;
    }
}
void DeliveryUI::DeliveryMenu(){
    dev = new Delivery(myplace);
    while(true){
        cout << "a: Get list of all active orders" << endl;
        cout << "r: Get list of ready orders" << endl;
        cout << "i: Get a specific order by index" << endl;
        cout << "b: Back" << endl;
        cout << "q: quit" << endl;
        char userin;
        cin >> userin;
        switch(tolower(userin)){
            case 'a':
                cout << "All active orders at" << endl;
                dev->GetOrders(cout);
                break;
            case 'r':
                cout << "All ready orders" << endl;
                dev->GetReadyOrders(cout);
                break;
            case 'i':
                int id;
                cout << "Select An order: " << endl;
                dev->GetOrders(cout);
                cin >> id;
                dev->GetThisOrder(cout,id-1);
                EditDelivery(id-1);
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
            dev->MarkPaid(index);
            break;
        }
        case 'd':{
            dev->MarkDelivered(index);
            break;
        }
        case 'r':{
            dev->MarkPaid(index);
            dev->MarkDelivered(index);
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
