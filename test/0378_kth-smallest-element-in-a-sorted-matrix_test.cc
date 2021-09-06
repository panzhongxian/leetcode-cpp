#include "0378_kth-smallest-element-in-a-sorted-matrix.h"

#include <algorithm>
#include <random>

#include "base.h"

TEST(S, Demo) {
  vector<int> v{1, 2, 3, 4, 4, 5, 6, 7, 7, 7, 8, 9};
  int col_len = 3;
  int row_len = 4;

  auto rng = std::default_random_engine{};
  std::shuffle(std::begin(v), std::end(v), rng);
  vector<vector<int>> matrix;
  for (int i = 0; i < row_len; i++) {
    vector<int> row;
    for (int j = 0; j < col_len; j++) {
      row.push_back(v[i * col_len + j]);
    }
    matrix.push_back(row);
  }
  for (auto& row : matrix) {
    sort(row.begin(), row.end());
  }
  sort(v.begin(), v.end());

  for (int k = 1; k <= v.size(); k++) {
    Solution s;
    int ret = s.kthSmallest(matrix, k);
    cout << "k:" << k << ", ret: " << ret << endl;
    EXPECT_EQ(ret, v[k - 1]);
  }
}
