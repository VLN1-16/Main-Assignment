#ifndef PREPERATION_H
#define PREPERATION_H
#include <cstdlib>
#include "place.h"
#include "order.h"

// #include "preperator.h"
#include "orderrepo.h"

/*
*
* The Idea with this UI is that the preperator always
* Has a pizza on screen, he can go next, prev, mark ready and mark in progress
* but his world is around the pizzza queue rather than orders for evryone else.
*/
using namespace std;

class PreperationUI{
    public:
        PreperationUI(Place Myplace);
        ~PreperationUI();
        void PreperationMenu();
        void WorkingMode();
    private:
        Place myplace;
        OrderRepo* orders;
};
#endif
