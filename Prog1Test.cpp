#include "MyObj.h"
#include <vector>
#include <iostream> // added 
#include <cstdlib> // added
#include <ctime>
#include <numeric> // added
#include <algorithm> // added
#include <cmath> // added
#include <fstream> // added
using namespace std;

vector<int> ShellSort(vector<MyObj>& , int);

void runAnalysis() {
    int sizesArr[] = {1000, 3000, 5000, 7000, 9000, 11000, 13000, 15000}; // all sizes necessary for analysis portion
    vector<int> sizes(sizesArr, sizesArr + sizeof(sizesArr) / sizeof(sizesArr[0])); // converts array to vector
    
    int trials = 100;
    
    ofstream outFile("results.csv");
    outFile << "n,code,avg_comparisons,std_dev" << endl; // output file
    
    // loops through each size in sizes vector
    for (size_t i = 0; i < sizes.size(); i++) {
        int n = sizes[i];
        cout << "Testing size: " << n << endl;
        for (int code = 0; code < 4; code++) {
            vector<long> comparisons; // stores comparisons for each trial
            MyObj obj; // create an instance of MyObj
            
            // runs experiment for specified number of trials
            for (int t = 0; t < trials; t++) {
                vector<MyObj> vec(n);
                obj.reset(); // resets comparison count for each trial
                ShellSort(vec, code);
                comparisons.push_back(obj.getCount()); // stores comparison count
            }
            
            double avg = accumulate(comparisons.begin(), comparisons.end(), 0.0) / comparisons.size(); // average # of comparisons across all trials
            double sq_sum = inner_product(comparisons.begin(), comparisons.end(), comparisons.begin(), 0.0); // sum of squares of the comparison to compute standard deviation
            double stddev = sqrt(sq_sum / comparisons.size() - avg * avg); // computes standard deviation of comparisons
            
            cout << "Code " << code << " | Avg Comparisons: " << avg << " | Std Dev: " << stddev << endl;
            outFile << n << "," << code << "," << avg << "," << stddev << endl;
        }
        cout << "-----------------------------\n";
    }
    outFile.close();
}

int main() {
    srand(time(0));
    runAnalysis();
    return 0;
}