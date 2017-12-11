#include "productrepo.h"
ProductRepo::ProductRepo(){
    productlist = new FileHandler<Product>(productfile);
}
ProductRepo::~ProductRepo(){
    if(productlist != nullptr)
        delete productlist;
}
void ProductRepo::AddProduct(Product product){
    if(productlist == nullptr)
        productlist = new FileHandler<Product>(productfile);
    productlist->AddProduct(product);
}
void ProductRepo::GetProducts(std::ostream &os){
    for(int i = 0; i < productlist->GetSize(); i++){
        os << "Product : " << i + 1 << std::endl;
        Product prod = productlist->at(i);
        os << prod;
    }
}
void ProductRepo::RemoveProduct(int index){
    productlist->RemoveProduct(index);
}
