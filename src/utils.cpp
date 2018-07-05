#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "utils.hpp"


bool Utils::validInput(std::string input) {

    for(int i=0; i <input.length();i++){
        if(!isdigit(input[i]))
            return false;
    }
    return true;
}

int Utils::mapChar(char c) {
    return int(c);
}