#include <vector>
using namespace std;
constexpr int magic = 1337;

class Solution {
 public:
  int superPow(int a, vector<int>& b) {
    a %= magic;
    vector<int> base(b.size(), 1);

    base[0] = a;
    for (int i = 1; i < b.size(); i++) {
      for (int j = 0; j < 10; j++) {
        base[i] = (base[i] * base[i - 1]) % magic;
      }
    }

    int ret = 1;
    for (int i = 0; i < b.size(); i++) {
      for (int j = 0; j < b[b.size() - i - 1]; j++) {
        ret = ret * base[i] % magic;
      }
    }
    return ret;
  }
};
