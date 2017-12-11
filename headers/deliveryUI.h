#ifndef DELIVERYUI_H
#define DELIVERYUI_H
#include "place.h"
#include "order.h"
#include "delivery.h"


/*
*
* The Idea with this UI is that the preperator always
* Has a pizza on screen, he can go next, prev, mark ready and mark in progress
* but his world is around the pizzza queue rather than orders for evryone else.
*/
using namespace std;

class DeliveryUI{
    public:
        DeliveryUI(Place Myplace);
        ~DeliveryUI();
        void DeliveryMenu();
        void EditDelivery(int index);
        //void WorkingMode();
    private:
        Place myplace;
        Delivery* dev;
};
#endif
