#ifndef PLACEREPO_H
#define PLACEREPO_H

#include "config.h"
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
        int GetNumberOfPlaces() const;
    private:
        FileHandler<Place>* placelist;
};

#endif
