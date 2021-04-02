class Solution {
 public:
  bool hasEvenNumber(int n) {
    int digits = 0;
    while (n) {
      n /= 10;
      digits++;
    }
    return !(digits & 1);
  }
  int findNumbers(vector<int>& nums) {
    int ret = 0;
    for (int n : nums) {
      if (hasEvenNumber(n)) {
        ret += 1;
      }
    }
    return ret;
  }
};
