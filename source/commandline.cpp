#include "commandline.h"


CommandLine::CommandLine(){
    places = new PlaceRepo();
}
CommandLine::~CommandLine(){
    if(places != nullptr)
        delete places;
}

void CommandLine::printMainMenu(){
    while(true){
        cout << "~Welcome to Main Menu~" << endl << endl;
        cout << "Press: " << endl;
        cout << "m: For management" << endl;
        cout << "s: For sales" << endl;
        cout << "p: For preparation" << endl;
        cout << "d: For delivery" << endl;
        cout << "h: Display help" << endl;
        cout << "q: Quit" << endl << endl;

        char userAns;
        cin >> userAns;

        switch(tolower(userAns)){
            case 'm':
                cout << "~Management~" << endl;
                managementView();
                break;
            case 's':
                cout << "~Salesperson~" << endl;
                salesPerson();
                break;
            case 'p':{
                cout << "~Preparation~" << endl;
                try{
                    Place myplace;
                    myplace = pickplace();
                    preperationView(myplace);
                }
                catch(IndexOutOfRangeException e){
                    cout << "Please select a place from the list" << endl;
                    cin.clear();
                    cin.ignore(80, '\n');
                }
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
            case 'h':{
                ifstream fout("data/help.txt");
                while(true){
                    string helpline;
                    getline(fout, helpline);
                    if(fout.eof()) break;
                    cout << helpline << endl;
                }
                break;
            }
            default:
                cout << "Not valid input!" << endl;
                break;
        }
    }
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
    cout << "Placeid : " << endl;
    return places->GetPlace(index - 1);
}
