#include "base.h"
class Solution {
 public:
  int lastStoneWeight(vector<int>& stones) {
    if (stones.size() == 0) {
      return 0;
    }
    if (stones.size() == 1) {
      return stones[0];
    }

    sort(stones.begin(), stones.end());
    int i = stones.back();
    stones.pop_back();
    int j = stones.back();
    stones.pop_back();
    if (i == j) {
      return lastStoneWeight(stones);
    } else {
      stones.push_back(i - j);
      return lastStoneWeight(stones);
    }
  }
};
