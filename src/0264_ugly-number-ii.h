#include <climits>
#include <set>
#include <vector>

using std::set;
using std::vector;
class Solution {
 public:
  int nthUglyNumber(int n) {
    set<int> s;
    s.insert(1);
    int i = 0;
    int ret;

    while (i < n) {
      ret = *s.begin();
      s.erase(s.begin());

      constexpr int limit_2 = INT_MAX / 2;
      constexpr int limit_3 = INT_MAX / 3;
      constexpr int limit_5 = INT_MAX / 5;

#define XX(n)                              \
  do {                                     \
    if (limit_##n > ret) s.insert(ret* n); \
  } while (0)

      if (ret % 5 == 0) {
        XX(5);
      } else if (ret % 3 == 0) {
        XX(5);
        XX(3);
      } else {
        XX(5);
        XX(3);
        XX(2);
      }
      i++;
    }
    return ret;
  }

 private:
  vector<int> ugly_nums;
};
