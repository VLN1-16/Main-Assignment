#ifndef PLACE_H
#define PLACE_H

#include "config.h"

#include <iostream>
#include <string>

class Place{
    public:
        Place();
        Place(char n[sizeOfplace],char addr[sizeOfplace],char p[8],bool active = true);
        Place(std::string name,std::string addr,char p[8], bool active = true);
        ~Place();
        void WriteBin(std::ostream& BinaryOut);
        void ReadBin(std::istream& BinaryIn);
        static int GetByteSize();
        char* GetNumber();
        friend std::ostream& operator<<(std::ostream &os, Place &place);
        friend std::istream& operator>>(std::istream &is, Place &place);

        bool operator ==(const Place& cmp);

    private:
        char name[sizeOfplace];
        char address[sizeOfplace];
        char phone[8];
        bool isActive; // is this location still active
};
#endif
