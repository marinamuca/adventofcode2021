#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
    vector<string> input;
    string number, gamma="", epsilon="";
    int ceros=0, ones=0, gammaDec=0, epsilonDec=0;
    
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

    for (int i=0; i<input[0].size(); i++){
       for (int j=0; j<input.size(); j++){
           if(input[j][i]=='0')
                ceros++;
            else
                ones++;
       }

       if(ceros>ones){
            gamma+='0';
            epsilon+='1';
       } else {
            gamma+='1';
            epsilon+='0';
       }

       ceros = 0;
       ones = 0;
    }

    int power=0;
    for(int i=gamma.size()-1; i>=0; i--){
        if(gamma[i]=='1')
            gammaDec+=pow(2, power);
        else 
            epsilonDec+=pow(2, power);
    
        power++;    
    }

    cout << "Gamma: " << gamma << "(" << gammaDec << ")" << endl;
    cout << "Epsilon: " << epsilon << "(" << epsilonDec << ")" << endl;
    cout << "Product: " << gammaDec * epsilonDec << endl;


    return EXIT_SUCCESS;

}