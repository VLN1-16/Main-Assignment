#include "place.h"

Place::Place(){
    name[0] = '\0';
    address[0] = '\0';
    phone[0] = '\0';
    isActive = true;
}
Place::Place(char n[sizeOfplace],char addr[sizeOfplace],char p[8],bool active){
    for(int i = 0; i < sizeOfplace;i++){
        name[i] = n[i];
        address[i] = addr[i];
    }
    for(int i = 0; i < 8;i++){
        phone[i] = p[i];
    }
    isActive = active;
}
Place::Place(std::string name,std::string addr,char p[8], bool active){
    for(int i = 0; i < sizeOfplace; i++){
        this->name[i] = name[i];
        if(name[i] == '\0') break;
    }
    for(int i = 0; i < sizeOfplace; i++){
        this->address[i] = addr[i];
        if(addr[i] == '\0') break;
    }
    for(int i = 0; i < 8; i++){
        this->phone[i] = p[i];
    }
}
Place::~Place(){}

int Place::GetByteSize() {
    return sizeof(char)*sizeOfplace*2 + 8*sizeof(char) + sizeof(bool);
}

std::ostream& operator<<(std::ostream &os, Place& place){
    os << place.name << ", ";
    os << place.address << ", ";
    os << "S:" << place.phone << std::endl;
    return os;
}
std::istream& operator>>(std::istream &is, Place &place){
    is >> place.name >> place.address >> place.phone;
    return is;
}
void Place::WriteBin(std::ostream& binaryOut){
    // Write out the int and the name
    binaryOut.write((char*)(name), sizeof(char)*sizeOfplace);
    binaryOut.write((char*)(address), sizeof(char)*sizeOfplace);
    binaryOut.write((char*)(phone), sizeof(char)*8);
    binaryOut.write((char*)(&isActive), sizeof(bool));
}
void Place::ReadBin (std::istream& binaryIn){
    binaryIn.read((char*)(name), sizeof(char)*sizeOfplace);
    binaryIn.read((char*)(address), sizeof(char)*sizeOfplace);
    binaryIn.read((char*)(phone), sizeof(char)*8);
    binaryIn.read((char*)(&isActive), sizeof(bool));
}
bool Place::operator ==(const Place& cmp){
    for(int i = 0; i < sizeOfplace; i++){
        if(cmp.name[i] != name[i]) return false;
        if(cmp.name[i] == '\0') break;
    }
    for(int i = 0; i < sizeOfplace; i++){
        if(cmp.address[i] != address[i]) return false;
        if(cmp.address[i] == '\0') break;
    }
    for(int i = 0; i < 8; i++){
        if(cmp.phone[i] != phone[i]) return false;
    }
    if(cmp.isActive != isActive) return false;
    return true;
}
char* Place::GetNumber(){
    return phone;
}
