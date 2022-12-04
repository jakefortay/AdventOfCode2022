
#include <stdio.h>
#include <fstream> 
#include <iostream>
#include <string> 

using namespace std; 

int main()
{
    ifstream newFile("text.txt");
    string input; 
    string testInput;
    int tempMax = 0; 
    int runningSum = 0; 

    while(getline(newFile,input)){
        
        cout << input << "cash" << endl;  
        
        if(input != ""){
            runningSum += stoi(input);
        }else{
            if(runningSum > tempMax){
                tempMax = runningSum; 
            }
            runningSum = 0;
        }
    }
    
    cout << tempMax; 
    
    return 0;
}

