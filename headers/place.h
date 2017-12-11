#ifndef PLACE_H
#define PLACE_H
#define sizeOfplace 100
#include <iostream>
class Place{
    public:
        Place();
        Place(char n[sizeOfplace],char addr[sizeOfplace],char p[8],bool active = true);
        ~Place();
        void WriteBin(std::ostream& BinaryOut);
        void ReadBin(std::istream& BinaryIn);
        static int GetByteSize();
        friend std::ostream& operator<<(std::ostream &os, Place &place);
        friend std::istream& operator>>(std::istream &is, Place &place);

        bool operator ==(Place& cmp);

    private:
        char name[sizeOfplace];
        char address[sizeOfplace];
        char phone[8];
        bool isActive; // is this location still active
};
#endif
