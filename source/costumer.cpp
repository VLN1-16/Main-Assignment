#include "costumer.h"
Costumer::Costumer(){
   firstName[0] = '\0'; 
   lastName[0]  = '\0';
   number[0] = '\0';
}
Costumer::Costumer(char FirstName[lengthOfName], char LastName[lengthOfName], char Number[8]){
    for(int i = 0; i < lengthOfName; i++){
        firstName[i] = FirstName[i];
        lastName[i]  = LastName[i];
    }
    for(int i = 0; i < 9; i++){
        number[i]    = Number[i];
    }
}
void Costumer::WriteBin(std::ostream& out){
    out.write((char*)(firstName), sizeof(char) * lengthOfName); // write first name
    out.write((char*)(lastName), sizeof(char) * lengthOfName); // write last name
    out.write((char*)(number), sizeof(char) * 8); // write number
}
void Costumer::ReadBin(std::istream& is){
    is.read((char*)(firstName), sizeof(char) * lengthOfName);
    is.read((char*)(lastName), sizeof(char) * lengthOfName);
    is.read((char*)(number), sizeof(char) * 8);
}
std::ostream& operator <<(std::ostream& out, Costumer& cost){
    out << cost.firstName << " " << cost.lastName << " " << cost.number << std::endl;
    return out;
}
std::istream& operator >>(std::istream& is, Costumer& cost){
    is >> cost.firstName >> cost.lastName >> cost.number;
    // check if the number is long enough
    for(int i = 0; i < 7; i++){
        if(cost.number[i] == '\0') throw badnumber();
        if((int)(cost.number[i]) < 48 || (int)(cost.number[i]) > 48 + 10) throw badnumber();
    }
    // check if it ends in the right place
    if(cost.number[7] != '\0') throw badnumber();
    return is;
}
