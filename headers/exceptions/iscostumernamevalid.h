#ifndef ISCOSTUMERNAMEVALID_H
#define ISCOSTUMERNAMEVALID_H

#include <string>
using namespace std;


class isCostumerNameValid
{
    public:
        isCostumerNameValid(string message);
        string getMessage();

    private:
        string message;
};

#endif // ISCOSTUMERNAMEVALID_H
