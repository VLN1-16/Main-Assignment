#include "commandline.h"


CommandLine::CommandLine(){
    places = new PlaceRepo();
}
CommandLine::~CommandLine(){
    if(places != nullptr)
        delete places;
}

void CommandLine::printMainMenu(){
    cout << "~Welcome to Main Menu~" << endl << endl;
    cout << "Press: " << endl;
    cout << "m: For management" << endl;
    cout << "s: For sales" << endl;
    cout << "p: For preparation" << endl;
    cout << "d: For delivery" << endl;
    cout << "q: Quit" << endl << endl;

    char userAns;
    cin >> userAns;

    switch(tolower(userAns)){
        case 'm':
            cout << "~Management~" << endl;
            managementView();
            break;
        case 's':
            //TO-DO: clear screen
            cout << "~Salesperson~" << endl;
            salesPerson();
            break;
        case 'p':{
            cout << "~Preparation~" << endl;
            Place myplace;
            myplace = pickplace();
            preperationView(myplace);
            break;
        }
        case 'd':{
            cout << "~Delivery~" << endl;
            Place myplace;
            myplace = pickplace();
            deliveryView(myplace);
            break;
        }
        case 'q':
            return;
        default:
            cout << "Not a valid input!" << endl;
            printMainMenu();
            break;
    }
    printMainMenu();
}

void CommandLine::managementView(){
    ManagerUI manager;
    manager.ManagerMenu();
}
void CommandLine::salesPerson(){
    SalesUI sales;
    sales.PrintSalesMenu();
}
void CommandLine::preperationView(Place place){
    PreperationUI prep(place);
    prep.PreperationMenu();
}
void CommandLine::deliveryView(Place place){
    DeliveryUI delivery(place);
    delivery.DeliveryMenu();
}
Place CommandLine::pickplace(){
    int index;
    places->GetPlaces(cout);
    cout << "Which place are you working at : ";
    cin >> index;
    return places->GetPlace(index - 1);
}
