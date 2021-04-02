class Solution {
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(),
         [](const vector<int>& a, const vector<int>& b) {
           return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
         });
    int ret = 1;
    vector<int> l(envelopes.size(), 1);
    for (int i = 0; i < envelopes.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (envelopes[i][0] > envelopes[j][0] &&
            envelopes[i][1] > envelopes[j][1] && l[i] < l[j] + 1) {
          l[i] = l[j] + 1;
          if (l[i] > ret) {
            ret = l[i];
          }
        }
      }
    }
    return ret;
  }
};
