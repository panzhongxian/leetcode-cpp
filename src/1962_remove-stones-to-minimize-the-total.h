#include <functional>
#include <map>
#include <vector>
using namespace std;

class Solution {
 public:
  int minStoneSum(vector<int>& piles, int k) {
    map<int, int, std::function<bool(const int&, const int&)>> m{
        [](const int& a, const int& b) { return a > b; }};
    for (int pile : piles) {
      m[pile]++;
    }
    for (int i = 0; i < k; i++) {
      auto it = m.begin();
      int val = it->first;
      it->second--;
      if (it->second == 0) {
        m.erase(it);
      }
      val = (val & 1) ? (val >> 1) + 1 : val >> 1;
      m[val]++;
    }
    int ret = 0;
    for (auto kv : m) {
      ret += kv.first * kv.second;
    }
    return ret;
  }
};
