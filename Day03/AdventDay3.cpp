#include <iostream> 
#include <fstream> 
#include <iomanip>
#include <vector> 
#include <string> 

using namespace std; 

int main(){

    ifstream newFile("text_3.txt");
    string line, subLine1, subLine2; 
    int lineSize; 

    vector<char> commonSack;
    vector<int> prioVals; 
    bool foundMatch = false;
    int value; 
    int sumVals = 0; 

    // Part 1 

    // while(getline(newFile,line)){
        
    //     lineSize = line.size();

    //     subLine1 = line.substr(0, lineSize / 2);
    //     subLine2 = line.substr(lineSize / 2, lineSize);

    //     foundMatch = false; 

    //     for(int i = 0; i < subLine2.size(); i++){
    //         if((subLine1.find(subLine2[i]) != string::npos) && (foundMatch == false)){
    //             commonSack.push_back(subLine2[i]);
    //             foundMatch = true; 
    //         }
    //     }
    // }

    // for(int i = 0; i < commonSack.size(); i++){
    //     value = int(commonSack[i]); 

    //     if(value > 96){
    //         value -= 96; 
    //     }
    //     else{
    //         value -= 38;
    //     }

    //     prioVals.push_back(value);
    // }


    // Part 2 

    vector<string> lineList;

    while(getline(newFile,line)){
        lineList.push_back(line);
        cout << line << endl; 
    }

    for(int i = 0; i < lineList.size(); i += 3){
        for(int j = 0; j < lineList[i].size(); j++){

            if((lineList[i + 1].find(lineList[i].at(j)) != string::npos) && (lineList[i + 2].find(lineList.at(j)) != string::npos)){
                value = int(lineList[i].at(j));
                if(value > 96){
                    value -= 96; 
                }
                else{
                    value -= 38;
                }
                cout << value << endl; 
                prioVals.push_back(value);
            }
        }
    }




    // for(int i = 0; i < commonSack.size(); i++){
    //     value = int(commonSack[i]); 

    //     if(value > 96){
    //         value -= 96; 
    //     }
    //     else{
    //         value -= 38;
    //     }

    //     prioVals.push_back(value);
    // }


    for(int i = 0; i < prioVals.size(); i++){
        sumVals += prioVals[i];
    }

    cout << endl << sumVals; 

    return 0; 
  
}