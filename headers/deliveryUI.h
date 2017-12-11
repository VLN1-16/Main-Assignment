#ifndef DELIVERYUI_H
#define DELIVERYUI_H
#include "place.h"
#include "order.h"

#include "preperator.h"

/*
*
* The Idea with this UI is that the preperator always
* Has a pizza on screen, he can go next, prev, mark ready and mark in progress
* but his world is around the pizzza queue rather than orders for evryone else.
*/
using namespace std;

class PreperationUI{
    public:
        DeliveryUI(Place Myplace);
        ~DeliveryUI();
        void DeliveryMenu();
        //void WorkingMode();
    private:
        Place myplace;
        Delivery* dev;
};
#endif
