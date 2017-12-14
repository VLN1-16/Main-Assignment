#include "placerepo.h"
PlaceRepo::PlaceRepo(){
    placelist = new FileHandler<Place>(placefile);
}
PlaceRepo::~PlaceRepo(){
    if(placelist != nullptr)
        delete placelist;
}
void PlaceRepo::AddPlace(Place p){
    if(NumberIsOk(p.GetNumber()))
        placelist->AddProduct(p);
}
void PlaceRepo::GetPlaces(std::ostream& os){
    for(int i = 0; i < placelist->GetSize(); i++){
        os << "===== Place : " << i + 1 << " =====" << std::endl;
        Place place = placelist->at(i);
        os << place << std::endl;
    }
}
Place PlaceRepo::GetPlace(int index){
    if(index >= placelist->GetSize() || index < 0) // if the pizza vector is empty, throw an exception
        throw IndexOutOfRangeException();
    return placelist->at(index);
}
void PlaceRepo::RemovePlace(int index){
    placelist->RemoveProduct(index);
}
bool PlaceRepo::NumberIsOk(const char numberToCheck[8]){
    for(int i = 0; i < 7; i++){
        if(numberToCheck[i] == '\0') throw BadNumber("Number has to be 7 digits");
        if((int)(numberToCheck[i]) < 48 || (int)(numberToCheck[i]) > 48 + 10) throw BadNumber("Number can only contain numbers");
    }
    if(numberToCheck[7] != '\0') throw BadNumber("Number can only be 7 digits");
    return true;
}
