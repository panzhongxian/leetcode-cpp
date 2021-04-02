class Solution {
 public:
  bool validMountainArray(vector<int>& A) {
    if (A.size() <= 2) {
      return false;
    }
    if (A[0] >= A[1]) {
      return false;
    }
    bool ret;
    bool up_to_top = true;
    for (int i = 1; i < A.size(); ++i) {
      if (up_to_top) {
        if (A[i] > A[i - 1]) {
          continue;
        }
        if (A[i] == A[i - 1]) {
          return false;
        }
        up_to_top = false;
      } else {
        if (A[i] >= A[i - 1]) {
          return false;
        }
      }
    }
    return !up_to_top;
  }
};
