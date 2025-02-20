# CS-3353-Program-1

Check Python version is at least >3.13
```
python3 --version
```

Install Python dependencies before compiling:
```
pip3 install matplotlib numpy pandas
```

To compile the files:
```
g++ -o Prog1Test ShellSort.cpp MyObj.cpp Prog1Test.cpp
```
To run the program:
```
./ProgTest1
```
The analysis section has not been implemented or edited. Only the `ShellSort` function has been implemented in the `ShellSort.cpp` file.

The runAnalysis() function has been implemented to be used for the Part II: Analysis section. CSV file is outputted afterwards, but if you would like to have multiple csv files, rename the file in line 20 of `Prog1Test.cpp`. Otherwise, the current .csv file will be updated accordingly to each run.

Example:
```
ofstream outFile("results_2.csv");
```

To run the Python file to obtain the `graphs.png`, run either of the two commands depending on MacOS or Windows.
```
python3 Prog1Graphs.py

python Prog1Graphs.py
```
