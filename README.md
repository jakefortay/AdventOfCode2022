# AdventOfCode2022

This is the journey, of how one man, one stellar man, took the trek that others were unwilling to go. To complete all 25 days of the advent of code 2022. 

---
To Run Thine Code -

---

Ex. Using Day 1 - (Inside of Day 1 Folder)

```
PS C:\Users\Jake\Desktop\AdventOfCode2022\Day01>
g++ -o Day1.exe AdventDay1.cpp

Previous error was running this command - 
g++ -o Day1.exe ./Day01/AdventDay1.cpp
Here we were already in the Day01 folder, then tried to navigate to a Day01 folder within that, which did not exist. 

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


