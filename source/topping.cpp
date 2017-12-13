#include "topping.h"

Topping::Topping() : Product() {}
Topping::Topping(char n[lengthOfName], int Price) {
    price = Price;
    SetName(n);
}
