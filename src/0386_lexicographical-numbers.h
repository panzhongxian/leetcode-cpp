class Solution {
 public:
  vector<int> lexicalOrder(int n) {
    vector<int> ret;
    int curr = 1;
    while (ret.size() < n) {
      if (curr <= n) {
        ret.push_back(curr);
        curr *= 10;
      } else {
        curr = curr / 10 + 1;
        while (curr % 10 == 0) {
          curr /= 10;
        }
      }
    }
    return ret;
  }
};
