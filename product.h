#ifndef PRODUCT_H
#define PRODUCT_H
#define sizeOfName 50
#define sizeOfDesc 150
#include <iostream>
class Product{
    public:
        Product();
        Product(int p, char n[sizeOfName], char desc[sizeOfDesc]);
        ~Product();
        int GetPrice() const;
        char* GetName();
        char* GetDescription();

        void SetPrice(int p);
        void SetName(char n[sizeOfName]);
        void SetDescription(char desc[sizeOfDesc]);

        friend std::ostream& operator<<(std::ostream &os, Product& prod);
        // friend std::istream& operator>>(std::istream &is, Product &prod);

    private:
        char name[sizeOfName];
        char description[sizeOfDesc];
        int price;

};
#endif
