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
        cout << "i: Select a specific order  to edit by index" << endl;
        cout << "c: Geta orders for a specific customers phonenumber" << endl;
        cout << "b: Back" << endl;
        cout << "q: quit" << endl;
        char userin;
        cin >> userin;
        switch(tolower(userin)){
            case 'a':
                cout << "All active orders at this place:" << endl;
                if(orders->GetNumberOfOrders(myplace) == 0){
                    cout << "There are no active orders for this place" << endl;
                    break;
                }
                orders->GetActiveOrders(cout,myplace);
                break;
            case 'r':
                cout << "All ready orders for this place: " << endl;
                if(orders->GetNumberOfReadyOrders(myplace) == 0){
                    cout << "There are no ready orders for this place" << endl;
                    break;
                }
                orders->GetReadyOrders(cout,myplace);
                break;
            case 'i':
                int id;
                cout << "Select An order: " << endl;
                cin >> id;
                try{
                    orders->ReadOrderAt(cout,id-1,myplace);
                    EditDelivery(id-1);
                }
                catch(IndexOutOfRangeException e){
                    cout << "Please select an valid order for this place" << endl;
                    cin.clear();
                    cin.ignore(80, '\n');
                }
                break;
            case 'c':
                char p[8];
                cout << "What is the customers phonenumber " << endl;
                cin >> p;
                try{
                    orders->GetOrdersByCostumer(cout,myplace,p);
                }
                catch(BadNumber e){
                    cout << "Exception was thrown with error: " << e.getMessage() << endl;
                    cin.clear();
                    cin.ignore(80, '\n');
                }
                catch(IndexOutOfRangeException e){
                    cout << "There are no orders for this phonenumber"<< endl;
                    cin.clear();
                    cin.ignore(80, '\n');
                }
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
    cout << "d: Deliver the order" << endl;
    cout << "r: Mark order as paid and deliver" << endl;
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
        cout << "This order has not been paid for" << endl;
    }

}
