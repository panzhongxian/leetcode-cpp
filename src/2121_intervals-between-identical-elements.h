#include <map>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<long long> getDistances(const vector<int>& arr) {
    map<int, vector<int>> locations;
    vector<long long> ret(arr.size(), 0);

    for (int i = 0; i < arr.size(); i++) {
      locations[arr[i]].push_back(i);
    }

    for (auto [k, v] : locations) {
      long long total_sum = 0;
      long long left = 0;
      for (int n : v) {
        total_sum += n - v[0];
      }
      for (int i = 0; i < v.size(); i++) {
        ret[v[left++]] = total_sum;
        if (left == v.size()) break;
        total_sum += (left * 2 - v.size()) * (v[left] - v[left - 1]);
      }
    }

    return ret;
  }
};
