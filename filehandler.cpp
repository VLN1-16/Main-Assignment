#include "filehandler.h"
template <typename T>
FileHandler<T>::FileHandler() {
    std::ifstream fin(toppingDatatFile, std::ios::binary);
    size = arraySize;
    prodList = new T[size];
    numberOfProds = 0;
    if ( fin.is_open()){
        while (true){
            T newProd;
            newProd.ReadBin(fin);
            if(fin.eof()){
                break;
            }
            AddProduct(newProd,false);
        }
    }
    fin.close();
}
template <typename T>
FileHandler<T>::~FileHandler(){
    if(prodList != NULL){
        delete [] prodList;
        prodList = NULL;
        numberOfProds = 0;
    }
}
template <typename T>
void FileHandler<T>::AddProduct(T tp,bool toFile){
    if (numberOfProds == size){
        Resize();
    }
    prodList[numberOfProds] = tp;
    numberOfProds++;
    if (toFile){
        std::ofstream fout(toppingDatatFile , std::ios::binary | std::ios::app);
        tp.WriteBin(fout);
        fout.close();
    }

}
template <typename T>
int FileHandler<T>::GetSize(){
    return numberOfProds;
}
template <typename T>
void FileHandler<T>::Resize() {
    T *tmp = new T[size];
    for (int i=0; i< size; i++){
        tmp[i] = prodList[i];
    }
    delete[] prodList;
    size *= 2;
    prodList = new T[size];
    for (int i=0; i< size/2; i++){
        prodList[i] = tmp[i];
    }
    delete[] tmp;
}
template <typename T>
std::ostream& operator<<(std::ostream &os, FileHandler<T> &prod){
    for(int i=0;i<prod.GetSize();i++){
        os << prod.prodList[i];
    }
    return os;
}
