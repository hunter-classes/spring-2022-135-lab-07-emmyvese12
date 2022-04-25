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
    std::cout << "============Task A: Remove Indentation============" << std::endl;
    std::string text1 = "       int x = 1;  ";
    std::string output1 = removeLeadingSpaces(text1);
    std::cout << "\nOriginal: " << text1 << std::endl;
    std::cout << "Indentation Removed: " << output1 << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;

    std::string text2 = "                         Hello, World!           ";
    std::string output2 = removeLeadingSpaces(text2);
    std::cout << "\nOriginal: " << text2 << std::endl;
    std::cout << "Indentation Removed: " << output2 << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;

    //open the file
    std::ifstream badfileog("bad-code.cpp");
    std::ofstream rmv_indentfile("removed-indentation.cpp"); //to write in the file removed-indentation.cpp aka fixed file
    std::string perline;
    std::string perlinermv;

    std::cout << "\nOriginal: " << "\n";

    while(getline(badfileog, perline)){ //print the file itself w/o removing leading spaces
        std::cout << perline << std::endl;
    }
    badfileog.close();

    std::ifstream badfilermv("bad-code.cpp");
    std::cout << "\nIndentation Removed: " << "\n";

    while (getline(badfilermv, perlinermv)){
        std::cout << removeLeadingSpaces(perlinermv) << std::endl; //prints out each input line without leading spaces
        rmv_indentfile << removeLeadingSpaces(perlinermv) << std::endl; //adds to the file removed-indentation.cpp
    }

    badfilermv.close();
    rmv_indentfile.close();



//task B
    std::cout << "\n============Task B: Adding Indentation============" << std::endl;
    std::cout << "\nBefore Indentation: " << std::endl;
    //open the file
    std::ifstream badfileog2("bad-code2.cpp");
    std::string perlineog2;

    while(getline(badfileog2, perlineog2)){ //print the original bad code file (just for before and after)
        std::cout << perlineog2 << std::endl;
    }
    badfileog2.close();

    std::cout << "\n";
    std::cout << "-------------------------------------------------" << std::endl;
    
    std::cout << "After Indentation: " << std::endl;
    addProperIndent("bad-code2.cpp"); //function in unindent.cpp

//task B additional test (CHANGE MADE BY JOHN)
    std::cout << "\n============Task B: Additional Test============" << std::endl;
    std::cout << "\nBefore Indentation: " << std::endl;
    //open the file
    std::ifstream badfileog3("sloppy.cpp");
    std::string perlineog3;
    while(getline(badfileog3, perlineog3)){ //print the original bad code file (just for before and after)
        std::cout << perlineog3 << std::endl;
    }
    badfileog3.close();
    std::cout << "\n";
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "After Indentation: " << std::endl;
    addProperIndent("sloppy.cpp"); //function in unindent.cpp

    return 0;
}
