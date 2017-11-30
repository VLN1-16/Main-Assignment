#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#define arraySize 10
#include <stddef.h>
#include <fstream>
#include <string>
template <typename T> class FileHandler {
    public:
        FileHandler(std::string DataFile){
            dataFile = DataFile;
            std::ifstream fin(dataFile, std::ios::binary);
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
        ~FileHandler(){
            if(prodList != NULL){
                delete [] prodList;
                prodList = NULL;
                numberOfProds = 0;
            }
        }
        void AddProduct(T product,bool toFile = true){
            if (numberOfProds == size){
                Resize();
            }
            prodList[numberOfProds] = product;
            numberOfProds++;
            if (toFile){
                std::ofstream fout(dataFile , std::ios::binary | std::ios::app);
                product.WriteBin(fout);
                fout.close();
            }
        }
        int GetSize(){
            return numberOfProds;
        }
        friend std::ostream& operator<<(std::ostream &os, FileHandler<T> &prod){
            for(int i=0;i<prod.GetSize();i++){
                os << prod.prodList[i];
            }
            return os;
        }
    private:
        T *prodList;
        void Resize(){
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
        int size;
        int numberOfProds;
        std::string dataFile;

};
#endif
