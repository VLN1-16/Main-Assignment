#include "place.h"

Place::Place(){
    name[0] = '\0';
    address[0] = '\0';
    phone[0] = '\0';
    isActive = true;
}
Place::Place(char n[sizeOfplace],char addr[sizeOfplace],char p[7],bool active){
    for(int i = 0; i < sizeOfplace;i++){
        name[i] = n[i];
        address[i] = addr[i];
    }
    for(int i = 0; i < 7;i++){
        phone[i] = p[i];
    }
    isActive = active;
}
Place::~Place(){}

int Place::GetByteSize() {
    return sizeof(char)*sizeOfplace*2 + 7*sizeof(char) + sizeof(bool);
}

std::ostream& operator<<(std::ostream &os, Place& place){
    os << place.name << " ";
    os << place.address << " ";
    os << place.phone << std::endl;
    return os;
}
std::istream& operator>>(std::istream &is, Place &place){
    is >> place.name >> place.address >> place.phone;
    return is;
}
void Place::WriteBin(std::ostream& binaryOut){
    // Write out the int and the name
    binaryOut.write((char*)(&name), sizeof(char)*sizeOfplace);
    binaryOut.write((char*)(&address), sizeof(char)*sizeOfplace);
    binaryOut.write((char*)(&phone), sizeof(char)*7);
    binaryOut.write((char*)(&isActive), sizeof(bool));
}
void Place::ReadBin (std::istream& binaryIn){
    binaryIn.read((char*)(&name), sizeof(char)*sizeOfplace);
    binaryIn.read((char*)(&address), sizeof(char)*sizeOfplace);
    binaryIn.read((char*)(&phone), sizeof(char)*7);
    binaryIn.read((char*)(&isActive), sizeof(bool));
}
