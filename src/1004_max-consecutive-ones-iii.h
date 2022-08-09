#include <vector>
using namespace std;
class Solution {
 public:
  int longestOnes(vector<int>& nums, int k) {
    int counter[2] = {0};
    int left = 0;
    int right = 0;

    while (right < nums.size()) {
      int num = nums[right];
      int remaining = k + counter[1] - (right - left);
      if (remaining > 0) {
        counter[nums[right]]++;
        right++;
      } else if (remaining == 0 && num == 1) {
        right++;
        counter[1]++;
      } else {
        counter[num]++;
        counter[nums[left]]--;
        left++;
        right++;
      }
    }
    return right - left;
  }
};
