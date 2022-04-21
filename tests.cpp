#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <string>
#include <cctype> 
#include <fstream>
#include "unindent.h"
#include "indent.h"
#include "doctest.h"

// g++ -std=c++11 -c tests.cpp

//task A --> remove indentation
TEST_CASE("Check if indentation is removed"){
    CHECK(removeLeadingSpaces("            int number = 400;") == "int number = 400;");
    CHECK(removeLeadingSpaces("char alpha = 'a';") == "char alpha = 'a';");
    CHECK(removeLeadingSpaces("                     Making sure that this works and removes the indentation up front! ") == "Making sure that this works and removes the indentation up front! ");

    std::string every_line1, every_line2;
    std::ifstream testing("test-sample.cpp"); //bad file
    std::string output1, output2;
    while (getline(testing, every_line1)){
        output1 += removeLeadingSpaces(every_line1);
        output1 += "\n";
    }
    testing.close();
    std::ifstream correct("correct-sample.cpp"); //correct file
    while (getline(correct, every_line2)){
        output2 += every_line2;
        output2 += "\n";
    }
    correct.close();
    CHECK(output1 == output2);
}