#include <algorithm>
#include <vector>
using namespace std;
class Solution {
 public:
  int fillCups(vector<int>& amount) {
    sort(amount.begin(), amount.end());

    // c >= a + b
    if (amount[2] >= amount[0] + amount[1]) return amount[2];

    int ret = 0;
    // a + b > c
    // => a, a, x

    if (amount[1] > amount[0]) {
      ret += amount[1] - amount[0];
      amount[2] -= amount[1] - amount[0];
      amount[1] = amount[0];
    }

    // a,a,a
    if (amount[1] == amount[2]) {
      if (amount[0] & 1) {
        return ret + 2 + 3 * (amount[0] >> 1);
      } else {
        return ret + 3 * (amount[0] >> 1);
      }
    }

    // a, a, x (x > a)  => n < a
    int n = amount[0] + amount[1] - amount[2];
    if (n & 1) {
      n++;
    }
    return ret + 3 * (n >> 1) + (amount[2] - n);
  }
};
