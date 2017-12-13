#ifndef INVALIDPIZZASIZE_H
#define INVALIDPIZZASIZE_H
#include <string>

using namespace std;

class InvalidPizzaSize
{
    public:
        InvalidPizzaSize(string message);
        string GetMessage();

    private:
        string message;
};

#endif // INVALIDPIZZASIZE_H
