#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int nextGreaterElement(int n) {
    vector<int> digits;
    int found = -1;
    int next_high_index = -1;
    int index = 0;
    while (n) {
      int digit = n % 10;
      if (found < 0 && !digits.empty() && digits.back() > digit) {
        found = index;
        for (int i = digits.size() - 1; i >= 0; i--) {
          if (next_high_index == -1) {
            next_high_index = i;
          } else if (digits[i] < digits[next_high_index] && digits[i] > digit) {
            next_high_index = i;
          }
        }
      }
      index++;
      digits.push_back(digit);
      n /= 10;
    }
    if (found < 0) {
      return -1;
    }
    swap(digits[next_high_index], digits[found]);
    sort(digits.begin(), digits.begin() + found, greater<int>());

    int64_t ret = 0;
    int64_t base = 1;
    for (int digit : digits) {
      ret += digit * base;
      base *= 10;
    }
    if (ret > INT_MAX) {
      return -1;
    }
    return ret;
  }
};
