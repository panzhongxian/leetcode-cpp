class Solution {
 public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    auto raw_arr = arr;
    sort(arr.begin(), arr.end());
    unordered_map<int, int> mp;
    int j = 1;
    for (int i : arr) {
      if (mp.find(i) == mp.end()) {
        mp[i] = j++;
      }
    }

    for (size_t i = 0; i < arr.size(); ++i) {
      arr[i] = mp[raw_arr[i]];
    }
    return arr;
  }
};
