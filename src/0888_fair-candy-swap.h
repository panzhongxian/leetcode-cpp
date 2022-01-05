#include "base.h"

class Solution {
 public:
  vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
    int sum1 = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
    int sum2 = accumulate(bobSizes.begin(), bobSizes.end(), 0);
    int diff = (sum1 - sum2) >> 1;

    unordered_set<int> s_bob;
    for (int i : bobSizes) {
      s_bob.insert(i);
    }
    for (int i : aliceSizes) {
      if (s_bob.find(i - diff) != s_bob.end()) {
        return vector<int>({i, i - diff});
      }
    }
    return vector<int>({-1, -1});
  }
};
