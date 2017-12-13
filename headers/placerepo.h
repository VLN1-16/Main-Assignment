#ifndef PLACEREPO_H
#define PLACEREPO_H

#define placefile "data/places.dat"

#include "filehandler.h"
#include "place.h"
#include "badnumber.h"

class PlaceRepo{
    public:
        PlaceRepo();
        ~PlaceRepo();
        void AddPlace(Place p);
        void GetPlaces(std::ostream& os);
        Place GetPlace(int index);
        void RemovePlace(int index); // NOT IMPLEMENTED
        bool NumberIsOk(const char numberToCheck[8]);
    private:
        FileHandler<Place>* placelist;
};

#endif
