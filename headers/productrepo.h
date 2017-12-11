#ifndef PRODUCTREPO_H
#define PRODUCTREPO_H

#define productfile "data/products.dat"

#include "filehandler.h"
#include "product.h"

class ProductRepo{
    public:
        ProductRepo();
        ~ProductRepo();
        void AddProduct(Product product);
        void GetProducts(std::ostream& os);
        void RemoveProduct(int index);
    private:
        FileHandler<Product>* productlist;
};
#endif
