#include "deliveryUI.h"

DeliveryUI(Place Myplace){
    myplace = Myplace;
    dev = nullptr;
}
~DeliveryUI(){
    if(dev != nullptr){
        delete dev;
    }
}
void DeliveryMenu(){
    dev = new Delivery(myplace);

    cout << "a: Get list of all orders" << endl;
    cout << "r: Get list of ready orders" << endl;
    cout << "i: Get a specific order by index" << endl;
    cout << "b: Back" << endl;
    cout << "q: quit" << endl;
    char userin;
    cin >> userin;
    switch(tolower(userin)){
        case 'a':{
            dev.GetOrders(cout);
        }
        case 'r':{
                cout << "Already at the first pizza!" << endl;

        }
        case 'i':{
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
