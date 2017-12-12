#include "placerepo.h"
PlaceRepo::PlaceRepo(){
    placelist = new FileHandler<Place>(placefile);
}
PlaceRepo::~PlaceRepo(){
    if(placelist != nullptr)
        delete placelist;
}
void PlaceRepo::AddPlace(Place p){
    placelist->AddProduct(p);
}
void PlaceRepo::GetPlaces(std::ostream& os){
    if(placelist == nullptr)
        placelist = new FileHandler<Place>(placefile);
    for(int i = 0; i < placelist->GetSize(); i++){
        os << "Place : " << i + 1 << std::endl;
        Place place = placelist->at(i);
        os << place;
    }
}
Place PlaceRepo::GetPlace(int index){ 
    return placelist->at(index);
}
void PlaceRepo::RemovePlace(int index){
    // this should set the active flag of a single place
    // this has to be implemented cleanly in filehandler 

    // That actually is not neccasery, since the information is written with the order
}
