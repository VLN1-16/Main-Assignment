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
    int index = 0;
    while(true){
        prep = new Preperator(myplace);
        // Preperator preperator;
        //  Print a single pizza, offer next pizza or previous pizza
        prep->GetPizza(cout, index);
        cout << "n: Next pizza" << endl;
        cout << "p: Prev pizza" << endl;
        cout << "c: Mark complete" << endl;
        cout << "b: Back" << endl;
        cout << "q: quit" << endl;
        char userin;
        cin >> userin;
        switch(tolower(userin)){
            case 'n':{
                index++;
            }
            case 'p':{
                if(index > 0){
                    index--;
                }
                else{
                    cout << "Already at the first pizza!" << endl;
                }
            }
            case 'c':{
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
}
