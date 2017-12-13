#include "badnumber.h"

BadNumber::BadNumber(){
    this->message = "An instance of bad number was initialized without a message";
}

BadNumber::BadNumber(string message){
    this->message = message;
}

string BadNumber::getMessage(){
    return message;
}



