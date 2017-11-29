#include "topping.h"

Topping::Topping() : Product() {}
Topping::Topping(char n[sizeOfName]) {
    price = 200;
    SetName(n);
}
Topping::~Topping() {}
