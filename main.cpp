/*
Emmy Veselinov
CSCI 135 Lab-07
Pretty-printing / Automatic Style Program
*/

#include <iostream>
#include <string>
#include <fstream>
#include "unindent.h"


int main(){
//task A
    std::cout << "\n============Task A: Remove Indentation============" << std::endl;
    std::string text1 = "       int x = 1;  ";
    std::string output1 = removeLeadingSpaces(text1);
    std::cout << "Original: " << text1 << std::endl;
    std::cout << "Indentation Removed: " << output1 << std::endl;
    std::cout << "\n";

    std::string text2 = "                         Hello, World!           ";
    std::string output2 = removeLeadingSpaces(text2);
    std::cout << "Original: " << text2 << std::endl;
    std::cout << "Indentation Removed: " << output2 << std::endl;
    std::cout << "\n";

    //file redirection --> make main --> ./main < bad-code.cpp
    std::ifstream badfile("bad-code.cpp");
    std::string perline;

    while (getline(badfile, perline)){ 
        std::cout << removeLeadingSpaces(perline) << std::endl; //prints out each input line without leading spaces
    }

    badfile.close();

    return 0;
}