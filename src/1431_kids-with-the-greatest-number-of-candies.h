class Solution {
 public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
    int max_val;
    for (auto n : candies) {
      if (n > max_val) {
        max_val = n;
      }
    }
    max_val -= extraCandies;
    vector<bool> ret(candies.size(), false);
    int i = 0;
    for (auto n : candies) {
      if (n >= max_val) {
        ret[i] = true;
      }
      i++;
    }
    return ret;
  }
};
