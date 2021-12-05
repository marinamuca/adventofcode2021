#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
    vector<int> input, sum;
    vector<string> output;
    int number, total=0, pos;
    
    cout << "Reading input..." << endl;

    if(argc == 1){
        cerr << "Pleas provide an input file" << endl;
        exit(EXIT_FAILURE);
    } else if(argc >2){
        cerr << "Error. Too many arguments." << endl;
        exit(EXIT_FAILURE);
    } 

    ifstream input_file(argv[1]);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << argv[1] << "'" << endl;
        exit(EXIT_FAILURE);
    }

    while (input_file >> number) {
        input.push_back(number);
    }

    for (int i=0; i<=input.size()-3; i++){  
        sum.push_back(input[i]+input[i+1]+input[i+2]); 
    }

    for (int i=0; i<sum.size(); i++){
        cout << sum[i] << endl;
        if(i!=0)
            if(sum[i]>sum[i-1])
                total++;
    }
    
    cout << "There are "<< total <<" sums that are larger than the previous measurement" << endl;


    return 0;

}