#include <iostream>
#include <string>
#include <cctype> //isspace that checks if a character is a whitespace
#include "unindent.h"

//takes in one line of code and returns its copy without leading spaces/tabs
std::string removeLeadingSpaces(std::string line){

    std::string result = "";
    bool nonSpace = false;


    for (int i = 0; i < line.length(); i++){
        char c = line[i];

        if (isspace(c) && nonSpace == false){ // for leading spaces
            nonSpace = false;
        }
        else if (!isspace(c)){ //if the char is not a space aka letter
            nonSpace = true;
            result += line[i];
        }

        else if (isspace(c) && nonSpace == true){ // if the char is a space but found after a non-space char (non-leading spaces)
            nonSpace = true;
            result += line[i];
        }
    }

    return result;

}

