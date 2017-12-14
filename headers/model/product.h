#ifndef PRODUCT_H
#define PRODUCT_H

#include "config.h"

#include <iostream>
#include <cstring>

class Product{
    public:
        Product();
        Product(int p, char n[lengthOfName]);
        Product(char n[lengthOfName], int p);
        virtual ~Product();
        virtual int GetPrice() const;
        virtual char* GetName();

        virtual void SetPrice(const int& p);
        virtual void SetName(const char n[lengthOfName]);
        virtual void SetName(const std::string  n);

        friend std::ostream& operator<<(std::ostream &os, Product& prod);
        friend std::istream& operator>>(std::istream &is, Product &prod);

        virtual void WriteBin(std::ostream& binaryOut);
        virtual void ReadBin (std::istream& binaryIn);

        bool operator ==(Product& prod1);
    protected:
        char name[lengthOfName];
        int price;

    private:

};
#endif
