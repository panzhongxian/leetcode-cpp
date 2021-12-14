class Solution {
public:
  vector<int> finalPrices(vector<int> &prices) {
    vector<int> ret(prices.size());
    stack<pair<int, int>> s;
    for (int i = 0; i < prices.size(); i++) {
      int price = prices[i];
      ret[i] = price;
      while (!s.empty() && price <= s.top().first) {
        ret[s.top().second] -= price;
        s.pop();
      }
      s.push(pair<int, int>{price, i});
    }
    return ret;
  }
};
