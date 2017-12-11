#include <iostream>
#include <fstream>
#include "place.h"

using namespace std;

int main(){
    // Place p("Kóp","Nýbýlavegur","5812345",true);
    // ofstream fout("data/temp.dat");
    // cout << p << endl;
    // p.WriteBin(fout);
    // fout.close();
    // Place a;
    // ifstream fin("data/temp.dat");
    // a.ReadBin(fin);
    // cout << a << endl;
    
    Place p("Kóp","Nýbýlavegur","5812345",true);
    Place a = p;
    cout << p << endl;
    cout << a << endl;
}
