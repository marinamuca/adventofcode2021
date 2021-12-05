#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
    vector<int> input;
    int number, total=0;
    
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

    while (inputFile >> number) {
        input.push_back(number);
    }

    for (int i=0; i<input.size(); i++){
        if(i!=0)
            if(input[i]>input[i-1])
                total++;

    }


    cout << "There are "<< total <<" measurements that are larger than the previous measurement" << endl;


    return EXIT_SUCCESS;

}