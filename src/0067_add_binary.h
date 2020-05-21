#include "base.h"
class Solution {
 public:
  string addBinary(string a, string b) {
    int i, j;
    if (a.length() < b.length()) {
      swap(a, b);
    }
    string ret(a);
    int carry = 0;
    i = a.length() - 1;
    j = b.length() - 1;
#define set_carry_and_result(bit) \
  switch (bit) {                  \
    case 0:                       \
      carry = 0;                  \
      ret[i] = '0';               \
      break;                      \
    case 1:                       \
      carry = 0;                  \
      ret[i] = '1';               \
      break;                      \
    case 2:                       \
      carry = 1;                  \
      ret[i] = '0';               \
      break;                      \
    case 3:                       \
      carry = 1;                  \
      ret[i] = '1';               \
      break;                      \
    default:                      \
      assert(false);              \
  }

    for (; j >= 0; --i, --j) {
      set_carry_and_result(a[i] + b[j] + carry - '0' - '0')
    }

    for (; i >= 0; --i) {
      set_carry_and_result(a[i] + carry - '0')
    }

    return carry ? "1" + ret : ret;
  }
};
