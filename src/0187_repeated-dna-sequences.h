#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

enum CharValue { A = 0, C = 1, G = 2, T = 3 };

string ValueStr(int i) {
  string ret;
  int mask = 0xc0000;
  int shift = 18;
  for (int j = 0; j < 10; j++) {
    int value = (mask & i) >> shift;
    switch (value) {
#define XX(v, c)      \
  case v:             \
    ret.push_back(c); \
    break;
      XX(A, 'A');
      XX(C, 'C');
      XX(G, 'G');
      XX(T, 'T');
#undef XX
    }
    mask >>= 2;
    shift -= 2;
  }
  return ret;
}

class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ret;
    if (s.size() <= 10) {
      return ret;
    }

    int cur_num = 0;
    unordered_map<int, int> counter;
    for (int i = 0; i < s.size(); i++) {
      cur_num <<= 2;
      cur_num &= 0xfffff;
      switch (s[i]) {
#define XX(v, c)  \
  case c:         \
    cur_num |= v; \
    break;
        XX(A, 'A');
        XX(C, 'C');
        XX(G, 'G');
        XX(T, 'T');
#undef XX
      }
      if (i < 9) {
        continue;
      }
      if (counter.find(cur_num) == counter.end()) {
        counter[cur_num] = 0;
      }
      counter[cur_num]++;
    }

    for (auto &kv : counter) {
      if (kv.second > 1) {
        ret.push_back(ValueStr(kv.first));
      }
    }
    return ret;
  }
};
