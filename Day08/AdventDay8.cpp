
#include <stdio.h>
#include <fstream> 
#include <iostream>
#include <string> 
#include <vector> 

using namespace std; 

int main(){

    ifstream newFile("text_8.txt");
    ifstream firstLine("text_8.txt");

    string first; 
    getline(firstLine,first);

    const int rowSize = first.size(); 

    char input; 
    int temp; 
    

    vector<vector<int>> grid;
    vector<int> tempVect = {};

    for(int i = 0; i < rowSize; i++){
        grid.push_back(tempVect);
    }

    int i = 0; 

    while(newFile >> input){

        temp = int(input) - 48;
        grid[i].push_back(temp);
        i++;

        if(i == rowSize){
            i = 0; 
        }


    }

    int treesVisible = 0; 
    int pos; 
    bool isVisNorth, isVisSouth, isVisEast, isVisWest; 
    int scenicScore; 
    int v1, v2, v3, v4, tempPos, runCount; 
    vector<int> scenicScores; 

    for(int i = 1; i < grid.size() - 1; i++){
        for(int j = 1; j < grid[i].size() - 1; j++){
            isVisNorth = true; 
            isVisSouth = true; 
            isVisEast = true;
            isVisWest = true; 

            bool endNow = false; 

            v1 = 0;
            v2 = 0;
            v3 = 0; 
            v4 = 0; 



            // cout << "Coord is : " << i << " " << j << " and equals " << grid[i][j] << endl; 

            // Checks upwards

            pos = j - 1;
            tempPos = pos; 

            while(pos >= 0){
                if(grid[i][pos] >= grid[i][j]){
                    pos = 0; 
                    isVisNorth = false; 
                }
                if(grid[i][tempPos] >= grid[i][j]){  
                    v1 = 1;
                }
                else{
                    v1++; 
                }
                pos--; 
            }
            
            // Checks downwards 

            pos = j + 1;
            tempPos = pos; 

            while(pos <= grid[i].size() - 1){
                if(grid[i][pos] >= grid[i][j]){
                    pos = grid[i].size() + 1; 
                    isVisSouth = false; 
                }
                if(grid[i][tempPos] >= grid[i][j]){  
                    v2 = 1;
                }
                else{
                    v2++; 
                }
                pos++;
            }
            
            // Checks to the left

            pos = i - 1;
            tempPos = pos; 

            while(pos >= 0){
                if(grid[pos][j] >= grid[i][j]){
                    pos = 0; 
                    isVisWest = false; 
                }
                if(grid[tempPos][j] >= grid[i][j]){  
                    v3 = 1;
                }
                else{
                    v3++; 
                }

                pos--; 
            }


            // Checks to the right 

            pos = i + 1; 
            tempPos = pos; 

            while(pos <= grid.size() - 1){
                if(grid[pos][j] >= grid[i][j]){
                    pos = grid.size() + 1; 
                    isVisEast = false; 
                }
                // cout << "Got here" << endl; 
                if(grid[tempPos][j] >= grid[i][j]){  
                    // cout << "Is " << grid[tempPos][j] << " greater than or equal to " << grid[i][j] << endl; 
                    v4 = 1;
                }
                else{
                    v4++; 
                }
  
                pos++; 
            }


        

            if(isVisNorth || isVisSouth || isVisEast || isVisWest){
                treesVisible++; 
            }


            // cout << "Scores are : " << v1 << "*" << v2 << "*" << v3 << "*" << v4 << endl;
            // cout << "Total is : " << v1 * v2 * v3 * v4 << endl << endl; 

            scenicScore = v1 * v2 * v3 * v4; 

            scenicScores.push_back(scenicScore);
        
        }
    }

    int edgesVisible = (grid.size() * 2) + (grid[0].size() * 2) - 4; 
    cout << edgesVisible << " " << treesVisible << endl; 
    int totalTrees = edgesVisible + treesVisible; 
    cout << endl << "Total trees is : " << totalTrees << endl; 

    int tempMax = scenicScores[0];

    for(int i = 0; i < scenicScores.size(); i++){
        if(scenicScores[i] >= tempMax){
            tempMax = scenicScores[i];
        }
    }

    cout << "Max scenic score is " << tempMax << endl; 

    // Done 

    return 0;

}

