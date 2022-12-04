
#include <stdio.h>
#include <fstream> 
#include <iostream>
#include <string> 
#include <vector> 

using namespace std; 

int main()
{

    // runningSum is the answer to part 1, topThreeTotal is the answer to part 2

    ifstream newFile("text.txt");
    string input; 
    string testInput;
    int tempMax = 0; 
    int runningSum = 0;
    vector<int> groupedValues;  

    while(getline(newFile,input)){
        
        if(input != ""){
            runningSum += stoi(input);
        }else{
            if(runningSum > tempMax){
                tempMax = runningSum; 
            }
            groupedValues.push_back(runningSum);
            runningSum = 0;
        }
    }
    
    vector<int> topThree; 
    int localMax = 0; 
    int counter = 0; 

    for(int j = 0; j < 3; j++){
        for(int i = 0; i < groupedValues.size(); i++){
            if(groupedValues[i] > localMax){
                localMax = groupedValues[i]; 
                counter = i;
            }
        }
        topThree.push_back(localMax);
        groupedValues.erase(groupedValues.begin() + counter);
        localMax = 0; 
    }

    int topThreeTotal = 0; 

    for(int i = 0; i < topThree.size(); i++){
        cout << topThree[i] << endl; 
        topThreeTotal += topThree[i];
    }

    cout << topThreeTotal; 


    return 0;

}

