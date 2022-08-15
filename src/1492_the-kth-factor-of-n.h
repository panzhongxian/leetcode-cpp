#include <deque>
using namespace std;
class Solution {
 public:
  int kthFactor(int n, int k) {
    deque<int> q1, q2;
    if (n == 1) {
      return k == 1 ? 1 : -1;
    }
    for (int i = 1; i < n; i++) {
      if (n % i == 0) {
        int j = n / i;
        if (j < i) {
          break;
        } else if (j == i) {
          q1.push_back(i);
          break;
        } else {
          q1.push_back(i);
          q2.push_front(j);
          if (q1.size() == k) {
            return q1.back();
          }
        }
      }
    }
    if (q1.size() + q2.size() < k) {
      return -1;
    } else if (q1.size() >= k) {
      return q1[k - 1];
    } else {
      return q2[k - q1.size() - 1];
    }
  }
};
