class Solution {
 public:
  int timeRequiredToBuy(vector<int> &tickets, int k) {
    int base = tickets[k];
    int ret = 0;
    for (int i = 0; i < tickets.size(); i++) {
      if (i <= k) {
        ret += min(base, tickets[i]);
      } else {
        ret += min(base - 1, tickets[i]);
      }
    }
    return ret;
  }
};
