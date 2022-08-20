#include <string>
using std::string;
constexpr int64_t mod_base = 1000000007;
class Solution {
 public:
  int multiply(int m, int n, int shift = 0) {
    int64_t ret = m;
    ret *= n;
    return (ret >> shift) % mod_base;
  }
  int numWays(string s) {
    if (s.size() < 3) return 0;
    int ones = 0;
    for (char c : s) {
      if (c == '1') {
        ones++;
      }
    }
    if (ones % 3) {
      return 0;
    }
    if (ones == 0) {
      return multiply(s.size() - 1, s.size() - 2, 1);
    }
    int case_num = 0;  // 0 left parts, 1 left zeros, 2 middle parts, 3 right
                       // zeros, 4 right parts
    int curr_ones = 0;
    int limit1 = ones / 3;
    int limit2 = limit1 << 1;

    int left_zeros = 0;
    int right_zeros = 0;
    for (int i = 0; i < s.size() && case_num < 4; i++) {
      switch (case_num) {
        case 0:
          if (s[i] == '1') {
            curr_ones++;
            if (curr_ones == limit1) {
              case_num = 1;
            }
          }
          break;
        case 1:
          if (s[i] == '1') {
            curr_ones++;
            if (curr_ones == limit2) {
              case_num = 3;
            } else {
              case_num = 2;
            }
          } else {
            left_zeros++;
          }
          break;
        case 2:
          if (s[i] == '1') {
            curr_ones++;
            if (curr_ones == limit2) {
              case_num = 3;
            }
          }
          break;
        case 3:
          if (s[i] == '1') {
            curr_ones++;
            case_num = 4;
          } else {
            right_zeros++;
          }
          break;
        case 4:
          break;
      }
    }
    return multiply(left_zeros + 1, right_zeros + 1);
  }
};
