#ifndef PLACEREPO_H
#define PLACEREPO_H

#define placefile "data/places.dat"

#include "filehandler.h"
#include "place.h"

class PlaceRepo{
    public:
        PlaceRepo();
        ~PlaceRepo();
        void AddPlace(Place p);
        void GetPlaces(std::ostream& os);
        Place GetPlace(int index);
        void RemovePlace(int index); // NOT IMPLEMENTED
    private:
        FileHandler<Place>* placelist;
};

#endif
