class Solution {
 public:
  bool threeConsecutiveOdds(vector<int>& arr) {
    int consecutive_odds_len = 0;
    int flags = 0;
    for (int n : arr) {
      flags <<= 1;
      flags &= 0b111;
      flags |= (n & 1);
      if (flags == 0b111) {
        return true;
      }
    }
    return false;
  }
};
