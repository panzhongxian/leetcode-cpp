#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int minSumOfLengths(const vector<int>& arr, int target) {
    vector<pair<int, int>> matched_pairs;
    int left = 0;
    int right = 0;
    int curr_sum = 0;
    while (right <= arr.size()) {
      if (curr_sum < target) {
        if (right == arr.size()) {
          break;
        }
        curr_sum += arr[right++];
      } else if (curr_sum > target) {
        curr_sum -= arr[left++];
      } else if (curr_sum == target) {
        matched_pairs.push_back({left, right});
        if (right == arr.size()) {
          break;
        }
        curr_sum += arr[right++] - arr[left++];
      }
    }
    int ret = INT_MAX;
    for (int i = 0; i + 1 < matched_pairs.size(); i++) {
      tie(left, right) = matched_pairs[i];
      for (int j = i + 1; j < matched_pairs.size(); j++) {
        auto [m, n] = matched_pairs[j];
        if (m < right) {
          continue;
        }
        ret = min(n - m + right - left, ret);
      }
    }
    return ret == INT_MAX ? -1 : ret;
  }
};
