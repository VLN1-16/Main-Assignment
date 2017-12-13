#include <iostream>
#include "commandline.h"


int main(){

    std::cout << "Developed by : Omar Hogni Gudmarsson, Bjarki Halldorsson, Iris Osk Ottarsdottir" << std::endl;
    std::cout << "As a final assignment for VLN1-16 at RU University" << std::endl;

    CommandLine CommandObj; //CommandLine object

    CommandObj.printMainMenu();


    return 0;
}
