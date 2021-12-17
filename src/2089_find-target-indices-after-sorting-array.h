class Solution {
 public:
  vector<int> targetIndices(vector<int>& nums, int target) {
    int less_than_cnt = 0;
    int target_cnt = 0;
    for (int num : nums) {
      if (num < target) {
        less_than_cnt++;
      } else if (num == target) {
        target_cnt++;
      }
    }
    vector<int> ret;

    for (int i = 0; i < target_cnt; i++) {
      ret.push_back(i + less_than_cnt);
    }
    return ret;
  }
};
