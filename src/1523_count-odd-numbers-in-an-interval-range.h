class Solution {
 public:
  int countOdds(int low, int high) {
    low |= 1;
    if (high & 1 == 1) {
      high++;
    }
    return (high - low + 1) / 2;
  }
};
