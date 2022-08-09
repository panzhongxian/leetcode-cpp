#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
 public:
  int minMoves2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int target = *(nums.begin() + (nums.size() - 1) / 2);
    int64_t result = 0;
    for (int num : nums) {
      result += abs(num - target);
    }
    return result;
  }
};
