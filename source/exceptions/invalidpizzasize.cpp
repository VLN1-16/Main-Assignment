#include "invalidpizzasize.h"

InvalidPizzaSize::InvalidPizzaSize(string message)
{
    this->message = message;
}

string InvalidPizzaSize::GetMessage(){
    return message;
}
