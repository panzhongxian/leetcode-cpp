#include "base.h"

class Solution {
 public:
  int findKthPositive(vector<int>& arr, int k) {
    int counter = 1;
    int missed_num = 0;
    for (int i = 0; i < arr.size();) {
      if (arr[i] != counter) {
        if (counter + (k - missed_num) - 1 < arr[i]) {
          return counter + (k - missed_num) - 1;
        }
        missed_num += arr[i] - counter;
        counter = arr[i++] + 1;
      } else {
        i++;
        counter++;
      }
    }

    return counter + (k - missed_num) - 1;
  }
};
