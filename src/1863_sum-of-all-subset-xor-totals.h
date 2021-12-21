class Solution {
 public:
  int highestBit(int n) {
    int ret = 0;
    while (n) {
      n >>= 1;
      ret++;
    }
    return ret;
  }
  int subsetXORSum(vector<int>& nums) {
    int total_cnt = (1 << nums.size());
    int* k = new int[total_cnt];
    k[0] = 0;

    for (int i = 1; i < total_cnt; i++) {
      int t = highestBit(i);
      k[i] = nums[t - 1] ^ k[i ^ (1 << (t - 1))];
    }
    int sum = 0;
    for (int i = 1; i < total_cnt; i++) {
      sum += k[i];
    }
    return sum;
  }
};
