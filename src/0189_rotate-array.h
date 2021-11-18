#include <vector>

using std::vector;

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    if (k == 0) {
      return;
    }

    int i = 0;
    int start_index, cur_index, next_index;
    int cur_num, next_num;
    start_index = 0;

    while (true) {
      cur_index = start_index;
      cur_num = nums[cur_index];
      while (true) {
        next_index = (cur_index + k) % nums.size();
        next_num = nums[next_index];
        nums[next_index] = cur_num;
        cur_num = next_num;
        cur_index = next_index;
        i++;

        if (cur_index == start_index) {
          if (i == nums.size()) return;
          break;
        }
      }
      start_index++;
    }
  }
};
