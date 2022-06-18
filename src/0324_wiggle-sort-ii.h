class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> ret(nums.size());
    int idx;
    int even_start = (nums.size() - 1) >> 1;
    int odd_start = nums.size() - 1;
    for (int i = 0; i < nums.size(); i++) {
      if (i & 1) {
        ret[i] = nums[odd_start--];
      } else {
        ret[i] = nums[even_start--];
      }
    }
    swap(nums, ret);
  }
};
