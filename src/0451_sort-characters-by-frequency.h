#include <queue>
#include <string>
#include <utility>
using namespace std;

class Solution {
 public:
  string frequencySort(string s) {
    int count[128] = {0};
    for (char c : s) {
      count[c]++;
    }
    auto comp = [](pair<char, int>& a, pair<char, int>& b) {
      return a.second < b.second;
    };
    priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> q(
        comp);
    for (int i = 0; i < 128; i++) {
      if (count[i] > 0) {
        q.push({i, count[i]});
      }
    }
    string ret;
    while (!q.empty()) {
      auto [c, v] = q.top();
      ret.insert(ret.end(), v, c);
      q.pop();
    }
    return ret;
  }
};
