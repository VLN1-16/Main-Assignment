#ifndef PRODUCT_H
#define PRODUCT_H
#define sizeOfName 50
#include <iostream>
class Product{
    public:
        Product();
        Product(int p, char n[sizeOfName]);
        virtual ~Product();
        virtual int GetPrice() const;
        virtual char* GetName();

        virtual void SetPrice(int p);
        virtual void SetName(char n[sizeOfName]);

        friend std::ostream& operator<<(std::ostream &os, Product& prod);
        friend std::istream& operator>>(std::istream &is, Product &prod);

        virtual void WriteBin(std::ostream& binaryOut);
        virtual void ReadBin (std::istream& binaryIn);
    protected:
        char name[sizeOfName];
        int price;

    private:

};
#endif
