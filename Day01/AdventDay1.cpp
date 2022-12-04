
#include <stdio.h>
#include <fstream> 
#include <iostream>
#include <string> 
#include <vector> 
#include <string.h>

using namespace std; 

int main()
{
    ifstream newFile("text.txt");
    string input; 
    int tempMax = 0; 
    int runningSum = 0; 
    int tempVal;
    vector<string> list; 
    

    
    while(getline(newFile,input)){
        
        cout << input << endl;  
        
        if(input != ""){
            runningSum += stoi(input);
        }else{
            if(runningSum > tempMax){
                tempMax = runningSum; 
            }
            runningSum = 0;
        }
    }
    
    // while(getline(newFile,input)){
    //     list.push_back(input);
    // }
    
    // for(int i = 0; i < list.size(); i++){
        
    //     cout << list[i] << endl;
        
    //     if(list[i] != ""){
    //         runningSum += stoi(list[i]);
    //     }else{
    //         if(runningSum > tempMax){
    //             tempMax = runningSum;
    //             runningSum = 0; 
    //         }
    //     }
        
        
    // }
    
    
    
    cout << tempMax; 
    
    return 0;
}

