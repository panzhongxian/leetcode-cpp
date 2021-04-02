#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    vector<int> ret;
    int left = -1;
    int right = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] < 0) {
        left = i;
      } else if (nums[i] == 0) {
        ret.push_back(0);
      } else if (nums[i] > 0) {
        right = i;
        break;
      }
    }
    while (true) {
      if (left == -1 && right == nums.size()) {
        break;
      } else if (left == -1) {
        ret.push_back(nums[right] * nums[right]);
        right++;
      } else if (right == nums.size()) {
        ret.push_back(nums[left] * nums[left]);
        left--;
      } else if (nums[left] + nums[right] > 0) {
        ret.push_back(nums[left] * nums[left]);
        left--;
      } else {  //
        ret.push_back(nums[right] * nums[right]);
        right++;
      }
    }
    return ret;
  }
};
