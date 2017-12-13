#ifndef BADNUMBER_H
#define BADNUMBER_H

#include <string>

using namespace std;

class BadNumber
{
    public:
        BadNumber();
        BadNumber(string message);
        string getMessage();

    private:
        string message;
};
#endif
