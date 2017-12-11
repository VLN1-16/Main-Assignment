#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#define arraySize 10
#include <iostream>
#include <cstddef>
#include <fstream>
#include <string>
#include <vector>
#include "exceptions.h"
template <typename T> class FileHandler {
    public:
        FileHandler(std::string DataFile){
            dataFile = DataFile;
            std::ifstream fin(dataFile, std::ios::binary);
            size = arraySize;
            prodList = nullptr;
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
            if(prodList != nullptr){
                delete [] prodList;
            }
        }
        void AddProduct(T& product, bool toFile = true){
            if(prodList == nullptr)
                prodList = new T[size];
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
        void EditProduct(const T& editeditem,const int index){
            if(index < 0 || index >= numberOfProds)
                throw IndexOutOfRangeException();
            std::cout << "this ran" << std::endl;
            prodList[index] = editeditem;
            WriteEntireList();
        }
        void RemoveProduct(int index){
            if(index < 0 || index >= numberOfProds){
                throw IndexOutOfRangeException();
            }
            for (int i = index; i < numberOfProds-1; i++){
                prodList[i] = prodList[i+1];
            }
            numberOfProds--;
            WriteEntireList();
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
        T operator[] (int index){
            return at(index);
        }
        const T at(int index){
            if(index < 0 || index >= numberOfProds){
                throw IndexOutOfRangeException();
            }
            T returnval = prodList[index];
            return returnval;
        }
    private:
        T *prodList;
        void Resize(){
            T *tmp = new T[size * 2];
            for (int i=0; i< size; i++){
                tmp[i] = prodList[i];
            }
            delete [] prodList;
            prodList = tmp;
            tmp = nullptr;
            size *= 2;
        }
        void WriteEntireList(){
            std::ofstream fout(dataFile , std::ios::binary);
            for(int i = 0; i < numberOfProds; i++){
                prodList[i].WriteBin(fout);
            }
            fout.close();
        }
        int size;
        std::string dataFile;
        int numberOfProds;

};
#endif
