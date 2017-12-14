#include "preperationUI.h"

PreperationUI::PreperationUI(Place Myplace){
    myplace = Myplace;
    orders = new OrderRepo();
}
PreperationUI::~PreperationUI(){
    if(orders != nullptr){
        delete orders;
    }
}
void PreperationUI::PreperationMenu(){
    WorkingMode();
}
void PreperationUI::WorkingMode(){
    int index = 0;

    while(true){
        //  Print a single pizza, offer next pizza or previous pizza
        try{
            orders->GetPizzaByPlace(cout, index, myplace);
        }
        catch(IndexOutOfRangeException e){
            cout << "There is no pizza in preparation at this place!" << endl;
            cin.clear();
            cin.ignore(80, '\n');
            return;
        }
        cout << "n: Next pizza" << endl;
        cout << "p: Prev pizza" << endl;
        cout << "v: Mark in progress" << endl;
        cout << "c: Mark complete" << endl;
        cout << "b: Back" << endl;
        cout << "q: quit" << endl;
        char userin;
        cin >> userin;
        switch(tolower(userin)){
            case 'n':
                if(index + 1 == orders->GetNumberOfPizzas()){
                    cout << "Already at the last pizza" << endl;
                }
                else{
                    index++;
                }
                break;
            case 'p':
                if(index > 0){
                    index--;
                }
                else{
                    cout << "Already at the first pizza!" << endl;
                }
                break;
            case 'c':
                orders->UpdatePizzaStatus(index, 2, myplace); // 2 means ready
                break;
            case 'v':
                orders->UpdatePizzaStatus(index, 1, myplace); // 1 means in progress
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
