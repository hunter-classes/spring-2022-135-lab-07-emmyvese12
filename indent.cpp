#include <iostream>
#include <string>

// returns the number of occurences of c in given line
int countChar(std::string line, char c){
    int track = 0;
    for (int i = 0; i < line.length(); i++){
        if (line[i] == c){
            track++;
        }
    }

    return track;

}
