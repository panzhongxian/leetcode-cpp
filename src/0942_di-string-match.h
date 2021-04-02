class Solution {
 public:
  vector<int> diStringMatch(string S) {
    vector<int> ret;
    int left = 0;
    int right = S.size();
    for (char c : S) {
      if (c == 'I') {
        ret.push_back(left++);
      } else {
        ret.push_back(right--);
      }
    }
    ret.push_back(left);
    return ret;
  }
};
