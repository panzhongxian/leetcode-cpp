#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    unordered_map<int, int> stat;
    for (int n : arr) {
      stat[n]++;
    }
    auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
      return a.second > b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(
        cmp);
    for (auto& [k, v] : stat) {
      q.push({k, v});
    }
    while (k > 0) {
      if (k >= q.top().second) {
        k -= q.top().second;
        q.pop();
      } else {
        return q.size();
      }
    }
    return q.size();
  }
};
