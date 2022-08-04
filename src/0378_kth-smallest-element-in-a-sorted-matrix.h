#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;

class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int> q;
    for (const auto& v : matrix) {
      for (const int n : v) {
        if (q.size() < k) {
          q.push(n);
        } else if (q.top() < n) {
          break;
        } else {
          q.pop();
          q.push(n);
        }
      }
    }
    return q.top();
  }
};
