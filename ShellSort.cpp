#include "MyObj.h"
#include <vector>

vector<int> ShellSort(vector<MyObj>& arr, int code)
{
  vector<int> res(arr.size());

  int n = arr.size();
  for(int i = 0; i < n; i++){
    res[i] = i;
  }

  for(int gap = n / 2; gap > 0; gap /= 2){
    for(int i = gap; i < n; i++){
      MyObj temp = arr[i];
      int tempIndex = res[i];
      int j = i;

      while (j >= gap && !(temp < arr[res[j - gap]])){
        arr[j] = arr[j - gap];
        res[j] = res[j - gap];
        j -= gap;
      }
      arr[j] = temp;
      res[j] = tempIndex;
    }
  }

  return res;
}
