#include "base.h"

class Solution {
 public:
  vector<string> fizzBuzz(int n) {
    vector<string> ret(n);
    for (int i = 0; i < n; i++) {
      ret[i] = to_string(i + 1);
    }
    for (int i = 3; i <= n; i += 3) {
      ret[i - 1] = "Fizz";
    }
    for (int i = 5; i <= n; i += 5) {
      ret[i - 1] = "Buzz";
    }
    for (int i = 15; i <= n; i += 15) {
      ret[i - 1] = "FizzBuzz";
    }
    return ret;
  }
};
