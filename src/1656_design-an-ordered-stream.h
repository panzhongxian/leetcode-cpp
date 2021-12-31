#include "base.h"
class OrderedStream {
 public:
  OrderedStream(int n) : v(vector<string>(n)) {}

  vector<string> insert(int idKey, string value) {
    v[idKey - 1] = value;
    if (idKey - 1 == last_index + 1) {
      last_index++;
      while (true) {
        if (last_index + 1 == v.size()) {
          return vector<string>(v.begin() + cur_start, v.end());
        }

        if (v[last_index + 1].empty()) {
          break;
        }
        last_index++;
      }
      vector<string> ret(v.begin() + cur_start, v.begin() + last_index + 1);
      cur_start = last_index + 1;
      return ret;
    }
    return vector<string>{};
  }

 private:
  int cur_start{0};
  int last_index{-1};
  vector<string> v;
};
