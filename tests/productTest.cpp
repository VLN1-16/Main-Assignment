#include <iostream>
#include <cassert>
#include <sstream>
#include "product.h"

using namespace std;
int main(){
    // test the basic data functions 
    Product pr(50, "thisisthenameoftheclass");
    assert (pr.GetPrice() == 50);
    pr.SetPrice(pr.GetPrice() + 120);
    assert (pr.GetPrice() == 170);

    // test input and output streams
    stringstream ss;
    ss << pr;
    Product pr2;
    ss >> pr2;
    assert(pr == pr2);

    // test binarywrite and binary read
    stringstream ss2;
    pr2.WriteBin(ss2);

    Product pr3;
    pr3.ReadBin(ss2);

    assert(pr2 == pr3); 

    // Done, if no memory leaks occured the code should be ok
    cout << "============================================================================== Class Product looks Ok ==============================================================================" << endl;
}
