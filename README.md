# AdventOfCode2022

This is the journey, of how one man, one stellar man, took the trek that others were unwilling to go. To complete all 25 days of the advent of code 2022. 

---
To Run Thine Code

---

```
g++ -o Day1.exe ./Day01/AdventDay1.cpp

./Day1.exe
```
--- 
Git Commands

---
```
git add . 
git commit -m "Message"
git push 
git pull
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


