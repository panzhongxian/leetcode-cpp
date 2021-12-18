class Solution {
 public:
  vector<int> maxSubsequence(vector<int>& nums, int k) {
    vector<int> index(nums.size(), 0);
    map<int, vector<int>> m;
    int counter = 0;
    for (int i = 0; i < nums.size(); i++) {
      m[nums[i]].push_back(i);
      index[i] = 1;
      counter++;
      if (counter > k) {
        auto it = m.begin();
        index[it->second.back()] = 0;
        it->second.pop_back();
        if (it->second.empty()) {
          m.erase(it);
        }
        counter--;
      }
    }
    vector<int> ret(k);
    for (int i = 0, j = 0; i < nums.size(); i++) {
      if (index[i] == 1) {
        ret[j++] = nums[i];
      }
    }
    return ret;
  }
};
