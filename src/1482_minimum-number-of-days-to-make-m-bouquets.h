#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
 public:
  int CheckBloom(const vector<int>& bloomDay, int k, int day) {
    int blooms = 0;
    int prev_flower_num = 0;
    for (int bloom_day : bloomDay) {
      if (bloom_day <= day) {
        prev_flower_num++;
        if (prev_flower_num >= k) {
          prev_flower_num -= k;
          blooms++;
        }
      } else {
        prev_flower_num = 0;
      }
    }
    return blooms;
  }

  int minDays(const vector<int>& bloomDay, int m, int k) {
    if (static_cast<int64_t>(m) * static_cast<int64_t>(k) > bloomDay.size()) {
      return -1;
    }

    auto [it1, it2] = minmax_element(bloomDay.begin(), bloomDay.end());
    int left = (*it1) - 1;
    int right = *it2;
    int mid;
    while (left + 1 < right) {
      mid = (left + right) / 2;
      if (CheckBloom(bloomDay, k, mid) >= m) {
        right = mid;
      } else {
        left = mid;
      }
    }
    return right;
  }
};
