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
    // This function does not deal with the possible exception
    placelist->RemoveProduct(index);
}
