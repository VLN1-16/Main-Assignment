#include "preperationUI.h"

PreperationUI::PreperationUI(Place Myplace){
    myplace = Myplace;
    prep = nullptr;
}
PreperationUI::~PreperationUI(){
    if(prep != nullptr){
        delete prep;
    }
}
void PreperationUI::PreperationMenu(){
    WorkingMode();
}
void PreperationUI::WorkingMode(){
    prep = new Preperator(myplace);
    int index = 0;

    while(true){
        std::cout << "Index is : " << index << std::endl;
        // Preperator preperator;
        //  Print a single pizza, offer next pizza or previous pizza
        try{
            prep->GetPizza(cout, index);
        }catch(IndexOutOfRangeException e){
            cout << "No pizza so far" << endl;
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
                index++;
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
                prep->UpdateStatus(index, 2); // 2 means complete
                break;
            case 'v':
                prep->UpdateStatus(index, 1); // 1 means in progress
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
