/*
Emmy Veselinov
CSCI 135 Lab-07
Pretty-printing / Automatic Style Program
*/

#include <iostream>
#include <string>
#include <fstream>
#include "unindent.h"
#include "indent.h"


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

    //open the file
    std::ifstream badfileog("bad-code.cpp");
    std::ofstream rmv_indentfile("removed-indentation.cpp"); //to write in the file removed-indentation.cpp aka fixed file
    std::string perline;
    std::string perlinermv;

    std::cout << "Original: " << "\n";

    while(getline(badfileog, perline)){ //print the file itself w/o removing leading spaces
        std::cout << perline << std::endl;
    }
    badfileog.close();

    std::ifstream badfilermv("bad-code.cpp");
    std::cout << "\nIndendation Removed: " << "\n";

    while (getline(badfilermv, perlinermv)){ 
        std::cout << removeLeadingSpaces(perlinermv) << std::endl; //prints out each input line without leading spaces
        rmv_indentfile << removeLeadingSpaces(perlinermv) << std::endl; //adds to the file removed-indentation.cpp
    }
    badfilermv.close();
    rmv_indentfile.close();
    


//task B
    std::cout << "\n============Task B: Adding Indentation============" << std::endl;
    std::cout << "Before Indentation: " << std::endl;
    //open the file
    std::ifstream badfileog2("bad-code2.cpp");
    std::string perlineog2;

    while(getline(badfileog2, perlineog2)){ //print the original bad code file (just for before and after)
        std::cout << perlineog2 << std::endl;
    }
    badfileog2.close();

    std::cout << "\n";
    std::cout << "After Indentation: " << std::endl;
    addProperIndent("bad-code2.cpp"); //function in unindent.cpp

}
