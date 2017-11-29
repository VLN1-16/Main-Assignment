#include "costumer.h"
Costumer::Costumer(){
   firstName[0] = '\0'; 
   lastName[0]  = '\0';
}
Costumer::Costumer(char FirstName[lengthOfName], char LastName[lengthOfName]){
    for(int i = 0; i < lengthOfName; i++){
        firstName[i] = FirstName[i];
        lastName[i]  = LastName[i];
    }
}
std::ostream& operator <<(std::ostream& out, Costumer& cost){
    out << cost.firstName << " " << cost.lastName;
    return out;
}
std::ifstream& operator >>(std::ifstream& is, Costumer& cost){
    return is;
}
