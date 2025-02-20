# CS-3353-Program-1

To compile the files:
```
g++ -o Prog1Test ShellSort.cpp MyObj.cpp Prog1Test.cpp
```
To run the program:
```
./ProgTest1.
```
The analysis section has not been implemented or edited. Only the `ShellSort` function has been implemented in the `ShellSort.cpp` file.

The runAnalysis() function has been implemented to be used for the Part II: Analysis section. CSV file is outputted afterwards, but if you would like to have multiple csv files, rename the file in line 20 of `Prog1Test.cpp`.

Example:
```
ofstream outFile("results_2.csv");
```
