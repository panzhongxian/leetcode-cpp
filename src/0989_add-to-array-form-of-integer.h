#include <vector>
using namespace std;
class Solution1 {
 public:
  vector<int> addToArrayForm(vector<int>& A, int K) {
    vector<int> B;
    vector<int> ret;
    while (K) {
      B.insert(B.begin(), K % 10);
      K = K / 10;
    }
    int carry = 0;
    auto it1 = A.rbegin();
    auto it2 = B.rbegin();

    while (it1 != A.rend() || it2 != B.rend()) {
      if (it1 != A.rend() && it2 != B.rend()) {
        ret.insert(ret.begin(), (*it1 + *it2 + carry) % 10);
        carry = (*it1 + *it2 + carry) / 10;
        it1++;
        it2++;
      } else if (it1 != A.rend()) {
        ret.insert(ret.begin(), (*it1 + carry) % 10);
        carry = (*it1 + carry) / 10;
        it1++;
      } else if (it2 != B.rend()) {
        ret.insert(ret.begin(), (*it2 + carry) % 10);
        carry = (*it2 + carry) / 10;
        it2++;
      }
    }
    if (carry) {
      ret.insert(ret.begin(), 1);
    }
    return ret;
  }
};

class Solution2 {
 public:
  vector<int> addToArrayForm(vector<int>& A, int K) {
    auto it = A.rbegin();
    int cur_digit;
    while (K) {
      if (it == A.rend()) {
        A.insert(A.begin(), K % 10);
        K = K / 10;
        it = A.rend();
        continue;
      }

      cur_digit = *it + K % 10;
      *it = cur_digit % 10;
      if (cur_digit == *it) {
        K = K / 10;
      } else {
        K = K / 10 + 1;
      }

      it++;
    }
    return A;
  }
};
