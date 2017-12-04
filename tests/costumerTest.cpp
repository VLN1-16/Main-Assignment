#include <iostream>
#include "costumer.h"
#include <cassert>
#include <sstream>
using namespace std;

int main(){
    // check if it is the same constructor and using setters
    Costumer cost("Alfreð","Jónsson","5812345");
    Costumer cost1;
    cost1.SetFirstName("Alfreð");
    cost1.SetLastName("Jónsson");
    cost1.SetNumber("5812345");
    assert(cost1 == cost);
    // compare instream and ostream methods
    stringstream ss; 
    ss << cost;
    Costumer cost2;
    ss >> cost2;
    assert (cost2 == cost);
    try{
        Costumer cost1("Alfreð","Jónsson","581234");
        assert ( 1 == 2 ); // This should never run
    } catch(badnumber){
        // ok
    }
    try{
        Costumer cost1("Alfreð","Jónsson","asdf");
        assert ( 1 == 2 ); // This should never run
    } catch(badnumber){
        // ok
    }
    // compare readBin And WriteBin
    stringstream ss2;

    cost.WriteBin(ss2);
    Costumer cost3;

    cost3.ReadBin(ss2);
    assert(cost3 == cost);
    // Sanity check valued ageinst known good
    // Done in all casses above
    cout << "============================================================================== Class costumer looks Ok  ==============================================================================" << endl;
}
