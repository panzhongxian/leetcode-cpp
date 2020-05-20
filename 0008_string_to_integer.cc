#include "base.h"
class Solution {
 public:
  int myAtoi(string str) {
    int ret = 0;
    bool neg_flag = false;
    size_t idx;
    // 1. split whitespace.
    for (idx = 0; idx < str.size(); ++idx) {
      if (str[idx] != ' ') {
        break;
      }
    }

    if (idx == str.size()) {
      return 0;
    }

    if (str[idx] == '+') {
      idx++;
    } else if (str[idx] == '-') {
      idx++;
      neg_flag = true;
    } else if (str[idx] < '0' || str[idx] > '9') {
      return 0;
    }

    while (str[idx] >= '0' && str[idx] <= '9') {
      int c = str[idx] - '0';
      if (!neg_flag) {
        // ret * 10 + c <= max: 2^31 - 1
        // ret * 10 <= max: 2^31 - 1 - c
        // ret <= (max: 2^31 - 1 - c) / 10
        if (ret > (2147483647 - c) / 10) {
          return 2147483647;
        }
        ret = ret * 10 + c;
      } else {
        // ret * 10 - c >= max: 2^31
        // ret * 10 >= max: 2^31 + c
        // ret >= (max: 2^31 + c) / 10
        if (ret < (c - 2147483648) / 10) {
          return -2147483648;
        }
        ret = ret * 10 - c;
      }
      idx++;
    }

    return ret;
  }
};

TEST(S, Demo) {
  Solution s;
#define test(x) EXPECT_EQ(s.myAtoi(x), atoi(x))
  test("   ");
  test("2147483647");
  test("-2147483648");
  test(" 1234");
  test(" 01234");
  test(" -123");
  test(" +123");
  test(" 1234abc");
  test(" -123abc");
  test(" +123abc");
  test("abcd");
  test(" abc");
}
