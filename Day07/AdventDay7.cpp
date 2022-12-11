
#include <stdio.h>
#include <fstream> 
#include <iostream>
#include <string> 
#include <vector> 

using namespace std; 

const int MAX_SIZE = 100000;

// UNFINISHED

int getSize(vector<string> list, vector<string> directories, vector<int> positions){

    for(int i = 0; i < positions.size(); i++){

    }

    return 0; 
}


int main(){

    fstream newFile("text_7.txt");
    string input, subLine, subString;
    vector<string> data; 
    vector<string> directories; 
    vector<int> positions; 

    while(getline(newFile, input)){
        data.push_back(input);
    }

    for(int i = 1; i < data.size(); i++){
        subLine = data.at(i);

        if(subLine.at(0) == '$' && subLine.at(2) == 'c' && subLine.at(5) != '.'){
            subString = subLine.substr(4,subLine.size() - 4);
            directories.push_back(subString);
            positions.push_back(i);
        }
        
    }

    for(int i = 0; i < directories.size(); i++){
        cout << directories.at(i) << " " << positions.at(i) << endl; 
    }



    return 0;

}

