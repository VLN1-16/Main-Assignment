#include "topping.h"

Topping::Topping() : Product() {}
Topping::Topping(char n[sizeOfName], int Price) {
    price = Price;
    SetName(n);
}
