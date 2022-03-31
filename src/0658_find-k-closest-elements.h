class Solution {
 public:
  bool less_than(vector<int>::iterator it1, vector<int>::iterator it2, int x) {
    return (abs(*it1 - x) < abs(*it2 - x)) ||
           (abs(*it1 - x) == abs(*it2 - x) && *it1 < *it2);
  }
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    auto it = upper_bound(arr.begin(), arr.end(), x);
    if (it == arr.begin()) {
      return vector<int>(arr.begin(), arr.begin() + k);
    } else if (it == arr.end()) {
      return vector<int>(arr.begin() + (arr.size() - k), arr.end());
    }

    vector<int>::iterator left, right;
    if (less_than(it, it - 1, x)) {
      left = right = it;
    } else {
      left = right = it - 1;
    }

    for (int i = 1; i < k; i++) {
      if (left == arr.begin()) {
        return vector<int>(arr.begin(), arr.begin() + k);
      } else if (right == arr.end()) {
        return vector<int>(arr.begin() + (arr.size() - k), arr.end());
      }
      if (less_than(left - 1, right + 1, x)) {
        left = left - 1;
      } else {
        right = right + 1;
      }
    }
    return vector<int>(left, right + 1);
  }
};
