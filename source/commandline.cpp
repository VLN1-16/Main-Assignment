#include "commandline.h"


CommandLine::CommandLine(){
}
CommandLine::~CommandLine(){}

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
        case 'd':
            cout << "~Delivery~" << endl;
            deliveryView(pickplace());

            break;
        case 'q':
            exit(0);
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
    DeliveryUI dev(place);
    dev.DeliveryMenu();
}
Place CommandLine::pickplace(){
    // User has to pick his location
    int index;
    Management* manager = new Management();
    manager->GetPlaces(cout);
    cout << "Which place are you working at : ";
    cin >> index;
    Place tobereturned;
    tobereturned = manager->GetPlace(index - 1);
    delete manager;
    return tobereturned;
}
