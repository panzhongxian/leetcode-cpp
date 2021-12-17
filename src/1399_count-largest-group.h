#include <algorithm>
#include <vector>

#include "base.h"

using std::min;
using std::vector;

class Solution {
 public:
  vector<int> vector_shift(const vector<int>& v, int n) {
    auto ret(v);
    for (int i = 0; i < n; i++) {
      ret.insert(ret.begin(), 1, 0);
    }
    while (ret.back() == 0) {
      ret.pop_back();
    }
    return ret;
  }

  void vector_add(vector<int>& v1, const vector<int>& v2) {
    int i = 0;
    for (; i < min(v1.size(), v2.size()); i++) {
      v1[i] = v1[i] + v2[i];
    }
    for (; i < v2.size(); i++) {
      v1.push_back(v2[i]);
    }
  }

  vector<int> f(int n) {
    if (n < 10) {
      return vector<int>(n + 1, 1);
    }
#define XX(base)                                  \
  do {                                            \
    if (n < base * 10) {                          \
      vector<int> ret;                            \
      vector<int> v(f(base - 1));                 \
      int i = 0;                                  \
      int j = 0;                                  \
      for (; i < n + 1 - base; i += base, j++) {  \
        vector_add(ret, vector_shift(v, j));      \
      }                                           \
      vector_add(ret, vector_shift(f(n - i), j)); \
      return ret;                                 \
    }                                             \
  } while (0);

    XX(10);
    XX(100);
    XX(1000);
    XX(10000);
    return vector<int>{};
  }

  int countLargestGroup(int n) {
    auto v = f(n);
    v.erase(v.begin());
    int max_group = 0;
    int ret = 0;
    for (int i = 0; i < v.size(); i++) {
      if (v[i] > max_group) {
        ret = 0;
        max_group = v[i];
      }
      if (v[i] == max_group) {
        ret++;
      }
    }
    return ret;
  }
};
