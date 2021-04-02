#include "base.h"
class Solution {
 public:
  class Quad {
   public:
    int Hex() {
      int ret = 0;
      for (auto it = quad_expr.rbegin(); it != quad_expr.rend(); it++) {
        ret = ret * 10 + vm[*it];
      }
      return ret;
    }
    void Incr() {
      int carry = 1;
      for (size_t i = 0; i < quad_expr.size(); ++i) {
        int cur = quad_expr[i] + carry;
        quad_expr[i] = cur % 7;
        carry = cur / 7;
      }
      if (carry) {
        quad_expr.push_back(1);
      }
    }
    bool Good() {
      for (auto digit : quad_expr) {
        if (digit == 2 || digit == 3 || digit == 4 || digit == 6) {
          return true;
        }
      }
      return false;
    }
    void Clear() {
      quad_expr.clear();
      quad_expr.push_back(0);
    }

   private:
    vector<int> quad_expr;
    const vector<int> vm{0, 1, 2, 5, 6, 8, 9};
  };

  int rotatedDigits(int N) {
    Quad quad;
    int ret = 0;
    while (quad.Hex() <= N) {
      if (quad.Good()) {
        ret += 1;
      }
      quad.Incr();
    }

    return ret;
  }
};
