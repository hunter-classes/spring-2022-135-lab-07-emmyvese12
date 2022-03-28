#include <iostream>
#include <string>
#include <cctype> //isspace that checks if a character is a whitespace
#include <fstream>
#include "unindent.h"
#include "indent.h"

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

//add the proper amount of tabs per line depending on the number of open and close braces
void addProperIndent(std::string filename){

    std::ifstream badfile2(filename);
    std::ofstream with_indentfile("added-indentation.cpp"); //open a stream to write in the fixed file added-indentation.cpp with the correct indents from the badfile
    std::string perline2;

    char openBrace = '{';
    char closeBrace = '}';
    int tabCount = 0;

    while (getline(badfile2, perline2)){

        // calculate the number of open and closed braces in a line
        int openCount = countChar(perline2, openBrace);
        int closeCount = countChar(perline2, closeBrace);

        // because the closing curly braces are going to be indented one level further 
        // than they should be, if closeCount is placed before the for loop
        if (closeCount == 1){ //if there is a closed bracket, the indentation is lowered by 1
            tabCount = tabCount - 1; 
        }

        for (int i = 0; i < tabCount; i++){
            perline2 = "\t" + perline2; //add a tab for each tabCount followed by the rest of the line each time
        }

        if (openCount == 1){ // if there is a open bracket, the indentation is increased by 1
            tabCount = tabCount + 1;
        }

        std::cout << perline2 << std::endl;
        with_indentfile << perline2 << std::endl; //add the same thing in the fixed file
        
        
    }
    
    //close both files
    with_indentfile.close();
    badfile2.close();


}