class Solution {
 public:
  int bitwiseComplement(int N) {
    if (N == 0) return 1;
    int sum = 0;
    int n = N;
    while (n) {
      n >>= 1;
      sum = (sum << 1) | 1;
    }
    return sum - N;
  }
};
