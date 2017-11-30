#include "toppings.h"

Toppings::Toppings() {
    std::ifstream fin(toppingDatatFile, std::ios::binary);
    size = arraySize;
    toppingList = new Topping[size];
    numberOfToppings = 0;
    if ( fin.is_open()){
        while (true){
            Topping newTop;
            newTop.ReadBin(fin);
            if(fin.eof()){
                break;
            }
            AddTopping(newTop,false);
        }
    }
    fin.close();
}
Toppings::~Toppings(){
    if(toppingList != NULL){
        delete [] toppingList;
        toppingList = NULL;
        numberOfToppings = 0;
    }
}
void Toppings::AddTopping(Topping tp,bool toFile){
    if (numberOfToppings == size){
        Resize();
    }
    toppingList[numberOfToppings] = tp;
    numberOfToppings++;
    if (toFile){
        std::ofstream fout(toppingDatatFile , std::ios::binary | std::ios::app);
        tp.WriteBin(fout);
        fout.close();
    }

}
int Toppings::GetSize(){
    return numberOfToppings;
}
void Toppings::Resize() {
    Topping *tmp = new Topping[size];
    for (int i=0; i< size; i++){
        tmp[i] = toppingList[i];
    }
    delete[] toppingList;
    size *= 2;
    toppingList = new Topping[size];
    for (int i=0; i< size/2; i++){
        toppingList[i] = tmp[i];
    }
    delete[] tmp;
}
std::ostream& operator<<(std::ostream &os, Toppings &topp){
    for(int i=0;i<topp.GetSize();i++){
        os << topp.toppingList[i];
    }
    return os;
}
