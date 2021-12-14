class Solution {
public:
  vector<int> replaceElements(vector<int> &arr) {
    vector<int> ret(arr.size());
    int max_val = -1;
    for (int i = arr.size() - 1; i >= 0; i--) {
      ret[i] = max_val;
      if (arr[i] > max_val) {
        max_val = arr[i];
      }
    }
    return ret;
  }
};
