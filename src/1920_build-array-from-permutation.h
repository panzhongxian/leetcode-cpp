class Solution {
 public:
  vector<int> buildArray(vector<int>& nums) {
    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == i) {
        continue;
      }
      m[i] = nums[i];
      if (nums[i] > i) {
        nums[i] = nums[nums[i]];
      } else {
        nums[i] = m[nums[i]];
        m.erase(nums[i]);
      }
    }
    return nums;
  }
};
