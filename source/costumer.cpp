#include "costumer.h"
Costumer::Costumer(){
   firstName[0] = '\0';
   lastName[0]  = '\0';
   number[0] = '\0';
}
Costumer::Costumer(char FirstName[lengthOfName], char LastName[lengthOfName], char Number[8]){
    if(!NumberIsOk(Number)) throw badnumber();
    SetFirstName(FirstName);
    SetLastName(LastName);
    SetNumber(Number);
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
    if(!cost.NumberIsOk(cost.number)) throw badnumber();
    return is;
}
bool Costumer::operator ==(Costumer& cost){
    for(int i = 0; i < lengthOfName; i++){
        if(firstName[i] == cost.firstName[i]){
            if(firstName[i] == '\0') break;
        }
        else{
            return false;
        }
    }
    for(int i = 0; i < lengthOfName; i++){
        if(lastName[i] == cost.lastName[i]){
            if(lastName[i] == '\0') break;
        }
        else{
            return false;
        }
    }
    for(int i = 0; i < 8; i++)
        if(cost.number[i] != number[i]) return false;
    return true;
}
const char* Costumer::GetFirstName(){
    return firstName;
}
const char* Costumer::GetLastName(){
    return lastName;
}
const char* Costumer::GetNumber(){
    return number;
}
void Costumer::SetFirstName(const char newFirstName[lengthOfName]){

        for(int i = 0; i < lengthOfName; i++){
            if(firstName[i] == '\0'){
                break;
            }
            if(!(isalpha(firstName[i]))) {
               throw isCostumerNameValid("Name can not include numbers!");

               }
            else{
                firstName[i] = newFirstName[i];
               }
        }


    }

void Costumer::SetLastName(const char newLastName[lengthOfName]){
    for(int i = 0; i < lengthOfName; i++){
        lastName[i] = newLastName[i];
    }
}
void Costumer::SetNumber(const char newNumber[8]){
    if(!NumberIsOk(newNumber)) throw badnumber();
    for(int i = 0; i <= 8; i++){
        number[i] = newNumber[i];
    }
}
bool Costumer::NumberIsOk(const char numberToCheck[8]){
    // check if the number is long enough
    for(int i = 0; i < 7; i++){
        if(numberToCheck[i] == '\0') return false;
        if((int)(numberToCheck[i]) < 48 || (int)(numberToCheck[i]) > 48 + 10) return false;
    }
    // check if it ends in the right place
    if(numberToCheck[7] != '\0') return false;
    return true;
}
