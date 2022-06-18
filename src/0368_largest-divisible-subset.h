struct Record {
  int prev_divisor_index{-1};
  int subset_length{1};
};

class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<Record> vv(nums.size());

    int max_len = 1;
    int max_subset_index = 0;

    for (int i = 0; i < nums.size(); i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (vv[i].subset_length < vv[j].subset_length + 1 &&
            nums[i] % nums[j] == 0) {
          vv[i].prev_divisor_index = j;
          vv[i].subset_length = vv[j].subset_length + 1;
        }
      }
      if (max_len < vv[i].subset_length) {
        max_len = vv[i].subset_length;
        max_subset_index = i;
      }
    }
    vector<int> ret;
    while (max_subset_index != -1) {
      ret.push_back(nums[max_subset_index]);
      max_subset_index = vv[max_subset_index].prev_divisor_index;
    }
    return ret;
  }
};
