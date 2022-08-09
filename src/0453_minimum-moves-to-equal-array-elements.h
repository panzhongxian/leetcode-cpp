#include <algorithm>
#include <vector>
using namespace std;
class Solution {
 public:
  int minMoves(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int ret = 0;
    int last_num = nums.back();
    for (int i = 0; i < nums.size(); i++) {
      int idx = nums.size() - i - 1;
      if (nums[idx] == last_num) {
        continue;
      }
      ret += (last_num - nums[idx]) * i;
      last_num = nums[idx];
    }
    return ret;
  }
};
