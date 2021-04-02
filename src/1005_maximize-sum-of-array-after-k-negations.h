#include <algorithm>
#include <vector>

class Solution {
 public:
  int largestSumAfterKNegations(std::vector<int>& A, int K) {
    std::sort(A.begin(), A.end());
    int neg_cnt = 0;
    for (int i : A) {
      if (i >= 0) {
        break;
      }
      neg_cnt++;
    }
    int sum = 0;
    if (neg_cnt >= K) {
      int i = 0;
      for (; i < K; ++i) {
        sum -= A[i];
      }
      for (; i < A.size(); ++i) {
        sum += A[i];
      }
    } else {
      for (int i = 0; i < A.size(); ++i) {
        if (i < neg_cnt) A[i] = -A[i];
        sum += A[i];
      }
      std::sort(A.begin(), A.end());
      if ((K - neg_cnt) & 1) {
        sum -= (A[0] << 1);
      }
    }
    return sum;
  }
};
