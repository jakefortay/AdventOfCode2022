
#include <stdio.h>
#include <fstream> 
#include <iostream>
#include <string> 
#include <vector> 

using namespace std; 

// hi :()

bool testChars(vector<char> vec, int position){
    bool flag = true;
    int numChars = 14; 
    vector<char> newVec; 

    for(int i = 0; i < numChars; i++){
        newVec.push_back(vec[position + i]);
    }

    int iterator = 0; 
    int temp = numChars; 

    for(int k = 0; k < numChars; k++){
        for(int j = 1; j < temp; j++){
            if(newVec[iterator] == newVec[iterator + j]){
                flag = false; 
            }
        }
        iterator += 1; 
        temp -= 1; 
    }

    return flag; 

}


int main()
{

    ifstream newFile("text_6.txt");

    char input; 

    int count, index(22); 

    vector<char> vec; 
    bool test,foundIndex(0); 

    while(newFile >> input){
        vec.push_back(input);
    }


    for(int i = 0; i < vec.size() - 5; i++){
        test = testChars(vec,i);
        if(test == true && foundIndex == false){
            index = i + 14; 
            foundIndex = true; 
        }
    }

    // cout << vec[index] << " " << vec[index + 1] << " " << vec[index + 2] << " " << vec[index + 3] << endl; 

    cout << index; 

    return 0;

}

