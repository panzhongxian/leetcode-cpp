class Solution {
 public:
  vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    vector<vector<int>> ret;
    sort(arr.begin(), arr.end());

    int min_diff = INT_MAX;
    int cur_diff;
    for (int i = 1; i < arr.size(); i++) {
      cur_diff = arr[i] - arr[i - 1];
      if (cur_diff < min_diff) {
        ret.clear();
        min_diff = cur_diff;
      }

      if (cur_diff == min_diff) {
        ret.push_back(vector{arr[i - 1], arr[i]});
      }
    }
    return ret;
  }
};
