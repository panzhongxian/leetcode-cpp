class Solution {
 public:
  bool hasAlternatingBits(int n) {
    bool prev, curr;
    curr = n & 1;
    n >>= 1;
    while (n) {
      prev = curr;
      curr = n & 1;
      if (curr == prev) {
        return false;
      }
      n >>= 1;
    }
    return true;
  }
};
