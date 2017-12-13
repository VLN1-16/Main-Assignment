#include "costumer.h"

Costumer::Costumer(){
   firstName[0] = '\0';
   lastName[0]  = '\0';
   number[0] = '\0';
}
Costumer::Costumer(char FirstName[lengthOfName], char LastName[lengthOfName], char Number[8]){
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
    if(!cost.NumberIsOk(cost.number)) throw BadNumber();
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
const bool Costumer::CompareNumber(const char n[8]){
    for(int i = 0; i < 8; i++)
        if(n[i] != number[i]) return false;
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
    if(newFirstName[0] == '\0')
        throw invalidCostumerName("First name is empty! ");

    for(int i = 0; i < lengthOfName; i++){
        firstName[i] = newFirstName[i];
        if(isdigit(newFirstName[i]))
            throw invalidCostumerName("Name can only consist of letter! ");
            if(newFirstName[i] == '\0') break;
    }
}

void Costumer::SetLastName(const char newLastName[lengthOfName]){
    if(newLastName[0] == '\0')
           throw invalidCostumerName("Last name is empty! ");

    for(int i = 0; i < lengthOfName; i++){
        lastName[i] = newLastName[i];
        if(isdigit(newLastName[i]))
            throw invalidCostumerName("Name can only consist of letter! ");
        if(newLastName[i] == '\0') break;
    }
}
void Costumer::SetNumber(const char newNumber[8]){
    if(NumberIsOk(newNumber)) {
        for(int i = 0; i <= 8; i++){
        number[i] = newNumber[i];
    }
    }
}
bool Costumer::NumberIsOk(const char numberToCheck[8]){
    // check if the number is long enough
    for(int i = 0; i < 7; i++){
        if(numberToCheck[i] == '\0') throw BadNumber("Number is too short");
        if((int)(numberToCheck[i]) < 48 || (int)(numberToCheck[i]) > 48 + 10) throw BadNumber("Number can not contain letter");
    }
    // check if it ends in the right place
    if(numberToCheck[7] != '\0') throw BadNumber("Number is too long");
    return true;
}
