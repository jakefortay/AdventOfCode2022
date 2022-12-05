
#include <stdio.h>
#include <fstream> 
#include <iostream>
#include <string> 
#include <vector> 

using namespace std; 

// In prog

int pointCalc(string yourMove, string opponentMove){
    int pointsAdded = 0;

    // X & A = Rock
    // Y & B = Paper
    // Z & C = Scissors 

    // 1/2/3 points are awarded for just picking rock/paper/scissors respectively
    // 0 Points for a loss, 3 points for a draw, 6 points for a win 

    if(yourMove == "X"){ 
        pointsAdded += 1; 
        if(opponentMove == "A"){
            pointsAdded += 3;
        }else if(opponentMove == "B"){
            
        }else{
            pointsAdded += 6; 
        }
    }else if(yourMove == "Y"){
        pointsAdded += 2; 
        if(opponentMove == "A"){
            pointsAdded += 6;
        }else if(opponentMove == "B"){
            pointsAdded += 3; 
        }else{

        }
    }else{
        pointsAdded += 3; 
        if(opponentMove == "A"){

        }else if(opponentMove == "B"){
            pointsAdded += 6; 
        }else{
            pointsAdded += 3; 
        }
    }

    return pointsAdded; 
}

int advancedPointCalc(string token, string oppMove){
    int pointsAdded = 0; 
    // X = Need to lose, Y = Need to draw, Z = Need to win  

    if(token == "X"){
        if(oppMove == "A"){         // They chose rock, and we have to lose so pick scissors
            pointsAdded += 3; 
        }else if(oppMove == "B"){   // They chose paper, and we have to lose so pick rock
            pointsAdded += 1; 
        }else if(oppMove == "C"){   // They chose scissors, and we have to lose so pick paper
            pointsAdded += 2; 
        }
    }
    if(token == "Y"){
        if(oppMove == "A"){         // They chose rock, and we have to draw so pick rock
            pointsAdded += (3 + 1); 
        }else if(oppMove == "B"){   // They chose paper, and we have to draw so pick paper
            pointsAdded += (3 + 2); 
        }else if(oppMove == "C"){   // They chose scissors, and we have to draw so pick scissors
            pointsAdded += (3 + 3); 
        }
    }
    if(token == "Z"){
        if(oppMove == "A"){         // They chose rock, and we have to win so pick paper
            pointsAdded += (6 + 2); 
        }else if(oppMove == "B"){   // They chose paper, and we have to win so pick scissors
            pointsAdded += (6 + 3); 
        }else if(oppMove == "C"){   // They chose scissors, and we have to win so pick rock
            pointsAdded += (6 + 1); 
        }
    }

    return pointsAdded;
}



int main()
{
    ifstream newFile("text_2.text");

    string input,oppMove;
    vector<string> moves; 
    int totalPoints1, totalPoints2;


    while(newFile >> input){
        moves.push_back(input);
    }

    for(int i = 1; i < moves.size(); i+=2){
        totalPoints1 += pointCalc(moves[i],moves[i-1]);
    }

    for(int i = 1; i < moves.size(); i+=2){
        totalPoints2 += advancedPointCalc(moves[i],moves[i-1]);
    }

    cout << totalPoints1 << endl << totalPoints2; 

    return 0;

}

