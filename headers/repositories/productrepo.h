#ifndef PRODUCTREPO_H
#define PRODUCTREPO_H

#include "config.h"
#include "filehandler.h"
#include "product.h"

class ProductRepo{
    public:
        ProductRepo();
        ~ProductRepo();
        void AddProduct(Product product);
        void GetProducts(std::ostream& os);
        void RemoveProduct(int index);
        Product GetProduct(int index);
        int GetNumberOfProducts() const;
    private:
        FileHandler<Product>* productlist;
};
#endif
