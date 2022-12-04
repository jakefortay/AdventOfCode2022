# AdventOfCode2022

This is the journey, of how one man, one stellar man, took the trek that others were unwilling to go. To complete all 25 days of the advent of code 2022. 

---
Code commands

---

```
g++ -o test.exe ./test.cpp

./test.exe
```
---
Code Formatting 

---

```cpp
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
```


