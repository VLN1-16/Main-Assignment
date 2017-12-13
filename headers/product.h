#ifndef PRODUCT_H
#define PRODUCT_H
#define sizeOfName 50
#include <iostream>
#include <cstring>

class Product{
    public:
        Product();
        Product(int p, char n[sizeOfName]);
        Product(char n[sizeOfName], int p);
        virtual ~Product();
        virtual int GetPrice() const;
        virtual char* GetName();

        virtual void SetPrice(const int& p);
        virtual void SetName(const char n[sizeOfName]);
        virtual void SetName(const std::string  n);

        friend std::ostream& operator<<(std::ostream &os, Product& prod);
        friend std::istream& operator>>(std::istream &is, Product &prod);

        virtual void WriteBin(std::ostream& binaryOut);
        virtual void ReadBin (std::istream& binaryIn);

        bool operator ==(Product& prod1);
    protected:
        char name[sizeOfName];
        int price;

    private:

};
#endif
