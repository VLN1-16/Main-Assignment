#ifndef TOPPING_H
#define TOPPING_H

#include "product.h"

class Topping : public Product {
    public:
        Topping();
        Topping(char n[lengthOfName], int Price = 200);

    private:


};
#endif
