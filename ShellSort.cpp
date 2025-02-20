#include "MyObj.h"
#include <vector>

vector<int> ShellSort(vector<MyObj>& arr, int code)
{
  vector<int> res; //holds values for h-list
  int n = arr.size(); // keeps track of the size of the array
  int max = 0; // max number

  if(code == 0){  // code 0
    res.push_back(1);
  }
  else if(code == 1){ // code 1
    while(pow(2, (max+1))-1 <= n){ // checks until array size is reached
      max++; //increasing number
    }
    for(int i=max; i>0; i--){
      res.push_back(pow(2, i)-1);
    }
  }
  else if(code == 2){ // code 2
    while((pow(3, max+1)-1)/2 <= n){ // checks until array size is reached
      max++; // increasing number
      cout << (pow(3, max+1)-1)/2 << endl;
    }
    for(int i=max; i>0; i--){
      res.push_back((pow(3, i)-1)/2);
    }
  }
  else if(code == 3){ // code 3
    int current = 1; // current number
    res.push_back(current);
    while(current < n){ // checking until c is greater than or equal to array size
      res.push_back(current*2);
      res.push_back(current*3);
      res.push_back(current*6);
      current = res.at(res.size()-1); //initalize c to just added number/item
    }

    for(int i=res.size()-1; i>res.size()-4; i--){ //removing numbers that may be larger than size of array
      if(res.at(i) > n){
        res.pop_back();
      }
    }

    vector<int> reversed; // temporarily holds reversed vector
    int j=0; // iteration for reversed vector
    for(int i=res.size()-1; i>=0; i--){ // reverses the hlist
        reversed.push_back(res.at(i));
    }

    res = reversed;
  }
  else{
    cerr << "You inputted an invalid value" << std::endl;
    return res;
  }

  for(int k=0; k<res.size(); k++){ // iterates through each gap value in h list
    int h = res[k]; // current gap value being used
    cout << "h occuring: " << h << endl << endl;

    for(int j=0; j<n; j++){ // insertion sort with gap h
      MyObj temp = arr[j]; // stores current element
      int i = j;
      while((i >= h) && (temp < arr[i-h])){
        arr[i] = arr[i-h]; // moves element at gap h ahead
        i = i - h; // shifts index by h positions
      }
      arr[i] = temp; // place temp value in correct position

    }

  }

  return res;
}
