#include <cassert>
#include <map>
#include <vector>

using std::multimap;
using std::pair;
using std::vector;

class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int row_len = matrix[0].size();
    assert(k <= matrix.size() * row_len);
    multimap<int, pair<int, int>> head_of_row;
    for (int i = 0; i < matrix.size(); i++) {
      head_of_row.insert({matrix[i][0], {i, 0}});
    }

    for (int i = 1; i < k; i++) {
      auto it = head_of_row.begin();

      auto row_idx = it->second.first;
      auto col_idx = it->second.second;
      head_of_row.erase(it);
      if (col_idx < row_len - 1) {
        head_of_row.insert(
            {matrix[row_idx][col_idx + 1], {row_idx, col_idx + 1}});
      }
    }
    return head_of_row.begin()->first;
  }
};
