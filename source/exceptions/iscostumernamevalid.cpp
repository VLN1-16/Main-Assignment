#include "iscostumernamevalid.h"

invalidCostumerName::invalidCostumerName(string message){
    this->message = message;
}

string invalidCostumerName::getMessage(){
    return message;
}

