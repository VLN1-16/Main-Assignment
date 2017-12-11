#ifndef PREPERATION_H
#define PREPERATION_H
#include "place.h"
#include "order.h"

using namespace std;

class PreperationUI{
    public:
        PreperationUI(Place Myplace);
        void PreperationMenu();
        void WorkingMode();
    private:
        Place myplace;
};
#endif
