class Solution {
 public:
  int numTrees(int n) {
    vector<int> fn;
    fn.push_back(1);
    for (int i = 1; i <= n; i++) {
      fn.push_back(0);
      for (j = 0; j < i; j++) {
        fn.back() += fn[j] * fn[i - 1 - j];
      }
    }
    return fn[n];
  }
};
