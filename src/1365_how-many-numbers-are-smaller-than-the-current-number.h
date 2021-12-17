class Solution {
 public:
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    vector<int> sorted_num(nums);

    sort(sorted_num.begin(), sorted_num.end());
    map<int, int> m;
    for (int i = 0; i < sorted_num.size(); i++) {
      int num = sorted_num[i];
      if (m.find(num) == m.end()) {
        m[num] = i;
      }
    }

    vector<int> ret(nums.size(), 0);
    for (int i = 0; i < ret.size(); i++) {
      ret[i] = m[nums[i]];
    }
    return ret;
  }
};
