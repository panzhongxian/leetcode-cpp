#include "base.h"

class Solution {
 public:
  bool isMonotonic(vector<int>& A) {
    int direction = 0;
    for (int i = 1; i < A.size(); ++i) {
      if (direction == 1 && A[i] < A[i - 1]) {
        return false;
      }
      if (direction == -1 && A[i] > A[i - 1]) {
        return false;
      }

      if (direction == 0) {
        if (A[i] > A[i - 1]) {
          direction = 1;
        } else if (A[i] < A[i - 1]) {
          direction = -1;
        }
      }
    }
    return true;
  }
};
