
#include <stdio.h>
#include <fstream> 
#include <iostream>
#include <string> 
#include <vector> 

using namespace std; 

int main(){

    ifstream newFile("text_5.txt");

    char input; 

    vector<vector<char>> mainVector; 
    vector<char> tempVector = {};

    int countChars = 0; 

    for(int i = 0; i < 9; i++){
        mainVector.push_back(tempVector);
    }

    bool test; 
    int index;

    while(newFile >> noskipws >> input && input != '1'){
        countChars++;

        test = !((countChars - 2) % 4);

        if(test && isalpha(input)){
            
            index = (countChars - 2) / 4; 
            mainVector[index].push_back(input);
            
        }

        if(countChars == 36){
            countChars = 0;
        }
     }

    cout << endl; 

    for(int i = 0; i < mainVector.size(); i++){
        for(int j = 0; j < mainVector[i].size(); j++){
            cout << mainVector[i][j];
        }
        cout << endl; 

    }

    int a = 0; 

    while(newFile >> noskipws >> input && (a < 34)){
        a++;
    }

    string newLine,subStr1; 
    string firstInt,secondInt,thirdInt; 
    int index1, index2; 
    int num1, num2, num3, tempVal; 

    int countOps = 0; 

    while(getline(newFile,newLine)){

        index = newLine.find(" "); 

        newLine = newLine.substr(index+1,newLine.back());

        index = newLine.find(" ");
        firstInt = newLine.substr(0,index);

        num1 = stoi(firstInt);

        index = newLine.find(" "); 
        newLine = newLine.substr(index+1,newLine.back());
        
        index = newLine.find(" ");
        newLine = newLine.substr(index+1,newLine.back());

        index = newLine.find(" ");

        secondInt = newLine.substr(0,index);

        num2 = stoi(secondInt) - 1;

        index = newLine.find("o");

        newLine = newLine.substr(index+1,newLine.back());

        thirdInt = newLine.substr(0,newLine.back());

        num3 = stoi(thirdInt) - 1;


        for(int i = 0; i < num1; i++){
            mainVector[num3].push_back(mainVector[num2][0]);
            mainVector[num2].erase(mainVector[num2].begin());
        }
        countOps++; 
    

    }

    cout << endl; 

    for(int i = 0; i < mainVector.size(); i++){
        for(int j = 0; j < mainVector[i].size(); j++){
            cout << mainVector[i][j];
        }
        cout << endl; 

    }

    cout << endl << "Performed " << countOps << " operations";

}


