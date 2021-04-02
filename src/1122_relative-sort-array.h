class Solution {
 public:
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> m;
    vector<int> arr2_cnt(arr2.size(), 0);
    vector<int> ret(arr1.size(), 0);
    for (int i = 0; i < arr2.size(); ++i) {
      m[arr2[i]] = i;
    }
    int p1 = ret.size() - 1;
    int p2 = p1;
    while (p1 >= 0) {
      if (m.find(arr1[p1]) == m.end()) {
        ret[p2--] = arr1[p1--];
      } else {
        arr2_cnt[m[arr1[p1--]]]++;
      }
    }
    int p = 0;
    for (int i = 0; i < arr2_cnt.size(); ++i) {
      int num = arr2[i];
      int cnt = arr2_cnt[i];
      for (int j = 0; j < cnt; ++j) {
        ret[p++] = num;
      }
    }
    sort(ret.begin() + p, ret.end());
    return ret;
  }
};
