#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
    int number, depth=0, position=0;
    string direction;
    
    if(argc == 1){
        cerr << "Please provide an input file" << endl;
        exit(EXIT_FAILURE);
    } else if(argc >2){
        cerr << "Error. Too many arguments." << endl;
        exit(EXIT_FAILURE);
    } 

    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "Could not open the file - '" << argv[1] << "'" << endl;
        exit(EXIT_FAILURE);
    }

    while (inputFile >> direction) {
        inputFile >> number;
        if (direction == "forward")
            position += number;
        else if (direction == "up")
            depth -= number;
        else if (direction == "down")
            depth += number;
    }

    cout << "Final depth: " << depth << endl;
    cout << "Final horizontal position: " << position << endl;
    cout << "Product: " << depth * position << endl;
    

    return EXIT_SUCCESS;

}